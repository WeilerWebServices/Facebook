#!/usr/bin/env python3
# Copyright 2004-present Facebook. All Rights Reserved.

import argparse
import re
import sys
import time
from multiprocessing import Process, Queue, Condition, Value

'''
***** Example call *****
python3 wikiwindows.py -e entities.txt -w 2 -d 5 -r data.txt

***** Example input *****

data.txt:
1 Illuminata (film)
2 Illuminata is a 1998 romantic comedy film directed by John Turturro and
    written by Brandon Cole and John Turturro, based on Cole's play.
3 The cinematographer was Harris Savides.

entities.txt:
Illuminata
film
1998
romantic comedy
John Turturro
Brandon Cole
s
play

***** Example output *****
1 <NULL> ( film Illuminata
2 Illuminata ( <NULL> ) Illuminata  film
3 1:Illuminata 1:( film ) <NULL> is a 1:Illuminata 1:(  Illuminata
4 1:film 1:) 1:Illuminata is a <NULL> romantic comedy film 1:film 1:)
    1:Illuminata  1998
5 1:) 1:Illuminata 1:is a 1998 <NULL> film directed 1:) 1:Illuminata
    1:is   romantic comedy
6 1:Illuminata 1:is 1:a 1998 romantic comedy <NULL> directed by 1:Illuminata
    1:is 1:a   film
7 1:1998 1:romantic comedy 1:film directed by <NULL> and written 1:1998
    1:romantic comedy 1:film    John Turturro
8 1:by 1:John Turturro 1:and written by <NULL> and John Turturro 1:by
    1:John Turturro 1:and Brandon Cole
9 1:and 1:written 1:by Brandon Cole and <NULL> , based 1:and 1:written
    1:by John Turturro
10 1:, 1:based 1:on Cole ' <NULL> play . 1:, 1:based 1:on   s
11 1:based 1:on 1:Cole ' s <NULL> . The 1:based 1:on 1:Cole play
12 1:puppet 1:sequences 1:were done by <NULL> Paska . 1:puppet 1:sequences
    1:were   Roman
13 1:done 1:by 1:Roman Paska . <NULL> for the 1:done 1:by 1:Roman   Music

***** Misc *****
Notice that you don't get anything from the third line of data.txt, as there
are no recognized entities. The final ngram in each output line is preceded
by a tab in the actual output, though it's hard to discern above.
'''

parser = argparse.ArgumentParser(
    description='Generates windowed examples for wikipedia files. By default,' +
    ' creates pairs of window<TAB>entity when used with entities.'
)
parser.add_argument('input_file', type=str, nargs='+',
    help='name of a input file in memnns format')
parser.add_argument('-o', '--output_file', type=str,
    help='name of a input file in memnns format')
parser.add_argument('-n', type=int, help='Max number of examples to process.')
parser.add_argument('-e', '--entities', type=str,
    help='entities file (each line specifies ngrams to always chunk together)')
parser.add_argument('-a', '--all_windows', action='store_true',
    help='if set, keeps all windows (not just ones entities). defaults to ' +
    ' True if entities file not present, False if it is present.')
parser.add_argument('-m', '--movie_in_all', action='store_true',
    help='if set, prepends movie to every line in example')
parser.add_argument('-i', '--inverse', action='store_true',
    help='if set, also write "inversed" version of each fact to the kb')
parser.add_argument('-r', '--replace_centroids', action='store_true',
    help='specifies whether to remove the center words of windows from ' +
    'their windows (defaults false, if true replaces word with <NULL>)')
parser.add_argument('-dm', '--dontmerge', action='store_true',
    help='default behavior merges lines from the same example--set this flag ' +
    'to disable and only consider windows from the same line in the file')
parser.add_argument('-w', '--window_size', type=str, default='1',
    help='sizes of windows PER SIDE around words to generate. eg 1 or ' +
    '1,2,3. ie "-w 1" for "hey world hey" produces "hey <NULL> hey"')
parser.add_argument('-d', '--double_dict', type=str,
    help='specifies whether to use a second dictionary for words within ' +
    'specified extended window. ie for "-w 1 -d 2", the ' +
    'sentence "hello world how are things" creates a window of "2:hello ' +
    '1:world <NULL> 1:are 2:things"')
parser.add_argument('-t', '--num_threads', type=int, default=1,
    help='number of threads to use')
args = vars(parser.parse_args())

beg = time.time()

if args['output_file']:
    out = open(args['output_file'], 'w')
else:
    out = sys.stdout

try:
    WS = [int(int(w)) for w in args['window_size'].split(',')]
    DW = None
    if args['double_dict']:
        DW = [int(int(w)) for w in args['double_dict'].split(',')]
        if len(WS) < len(DW):
            raise RuntimeError('must have at least as many window sizes as ' +
                               'double-dict extended window sizes.')
except ValueError:
    raise ValueError('Incorrect format for window size, should be CSV integers')

ent_list = []
re_list = []
entities = {}
ent_rev = {}
if 'entities' in args:
    if args['output_file']:
        print('Processing entity file...')
    with open(args['entities']) as read:
        for l in read:
            l = l.strip()
            if len(l) > 0:
                ent_list.append(l)
    ent_list.sort(key=lambda x: -len(x))
    for i in range(len(ent_list)):
        k = ent_list[i]
        v = '__{}__'.format(i)
        entities[k] = v
        ent_rev[v] = k
    re_list = [
        (
            re.compile('\\b{}\\b'.format(re.escape(e))),
            '{}'.format(entities[e])
        ) for e in ent_list
    ]
else:
    args['all_windows'] = True

splitter = re.compile('\\b.*?\S.*?(?:\\b|$)')
q_out = Queue()


def process_example(ex):
    windows = []
    if 'entities' in args:
        # replace entities with single tokens
        for r, v in re_list:
            ex = r.sub(v, ex)
    if args['dontmerge']:
        chunks = ex.split('\n')
    else:
        ex = ex.replace('\n', ' ')
        chunks = [ex]

    split = [t.strip() for t in splitter.findall(chunks[0])]
    movie = split.pop(0)
    if 'entities' in args:
        # revert movie token
        for k, v in ent_rev.items():
            if k in movie:
                movie = movie.replace(k, v)
                break
    for i in range(len(chunks)):
        chunk = chunks[i]
        if i > 0:
            split = [t.strip() for t in splitter.findall(chunk)]
        sz = len(split)
        for i in range(sz):
            if args['all_windows'] or split[i] in ent_rev:
                # loop over window sizes
                for j in range(len(WS)):
                    ws = WS[j]  # current window size
                    win = []
                    # create window
                    for w in range(max(i - ws, 0), min(i + ws + 1, sz)):
                        if w == i and args['replace_centroids']:
                            win.append('<NULL>')
                        else:
                            win.append(split[w])

                    # now check for second-dict window
                    # (need an non-nil d value higher than w)
                    use_second_dict = (
                        DW is not None and
                        j < len(DW) and
                        DW[j] > ws
                    )
                    if use_second_dict:
                        dw = DW[j]
                        b1 = max(i - dw, 0)
                        b2 = max(i - ws, 0)
                        b3 = min(i + ws + 1, sz)
                        b4 = min(i + dw + 1, sz)
                        pre = (
                            ['1:{}'.format(e) for e in split[b1:b2]]
                            if b1 < b2 else []
                        )
                        post = (
                            ['1:{}'.format(e) for e in split[b3:b4]]
                            if b4 > b3 else []
                        )
                        win = pre + win + post

                    join = ' '.join(win)
                    if 'entities' in args:
                        # put entities back in
                        skip_idx = 0
                        while True:
                            fst_idx = join.find('__', skip_idx)
                            if fst_idx > 0:
                                snd_idx = join.find('__', fst_idx + 2)
                                k = join[fst_idx:snd_idx + 2]
                                if k in ent_rev:
                                    join = join.replace(k, ent_rev[k])
                                else:
                                    skip_idx = snd_idx + 2
                            else:
                                break
                    sentence = join
                    if args['movie_in_all']:
                        if use_second_dict:
                            sentence = '1:' + movie + ' ' + sentence
                        else:
                            sentence = movie + ' ' + sentence
                    if args['inverse']:
                        sentence = '__WINDOW_CENTER__ ' + sentence
                    center = (
                        ent_rev[split[i]] if split[i] in ent_rev else split[i]
                    )
                    if not (args['inverse'] and center == movie):
                        windows.append((
                            sentence,
                            center
                        ))
                    if args['inverse']:
                        i_join = join
                        if args['replace_centroids']:
                            i_join = i_join.replace('<NULL>', center)
                        windows.append((
                            '__MOVIE__ ' + i_join,
                            movie
                        ))
    q_out.put(
        '\n'.join(
            '{} {}'.format(
                i + 1, '\t'.join(windows[i])
            )
            for i in range(len(windows))
        ) + '\n\n'
    )


# multithreading code
finished = Condition()
queued_exs = Value('i', 0)
proced_exs = Value('i', 0)
# keep at most 100 examples ready per thread queued (to save memory)
q = Queue(args['num_threads'] * 100)


def load(ex):
    global queued_exs
    queued_exs.value += 1
    q.put(ex)


def run():
    while True:
        ex = q.get()
        process_example(ex)


def write():
    global proced_exs
    while True:
        output = q_out.get()
        out.write(output)
        with proced_exs.get_lock():
            proced_exs.value += 1
        if q_out.empty() and queued_exs.value - proced_exs.value == 0:
            out.flush()
            with finished:
                finished.notify_all()


threads = []
threads.append(Process(target=write))
for i in range(args['num_threads']):
    threads.append(Process(target=run))
for t in threads:
    t.start()
if args['output_file']:
    print('Executing with {} threads.'.format(args['num_threads']))

mid = time.time()

for f in args['input_file']:
    if args['output_file']:
        # output is free to print debug info
        print('Processing file {}...'.format(f))
    with open(f) as read:
        first = True
        cnt_exs = 0
        full_ex = ''

        for line in read:
            line = line.strip()
            if line == '':
                continue
            idx = int(line[:line.find(' ')])
            line = line[line.find(' ') + 1:]
            if idx != 1 or full_ex == '':
                full_ex = full_ex + line + '\n'
                continue  # next line
            else:
                cnt_exs += 1
                load(full_ex.strip())
                if args['n'] is not None and cnt_exs >= args['n']:
                    full_ex = ''
                    break
                full_ex = line + '\n'
        # process last full_ex if out of new lines
        if full_ex != '':
            load(full_ex.strip())

while queued_exs.value - proced_exs.value > 0:
    with finished:
        finished.wait()

out.close()

for t in threads:
    t.terminate()

fin = time.time()
if args['output_file']:
    print('Time processing entities: {} s'.format(round(mid - beg)))
    print('Time processing examples: {} s'.format(round(fin - mid)))
    print('Total time: {} s'.format(round(fin - beg)))
