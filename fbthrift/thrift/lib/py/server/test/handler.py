# Copyright (c) Facebook, Inc. and its affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

try:
    import asyncio
except Exception:
    import trollius as asyncio

from thrift_asyncio.tutorial import Calculator as AsyncCalculator
from thrift_asyncio.sleep import Sleep as AsyncSleep
from thrift_asyncio.sleep.ttypes import OverflowResult


class AsyncCalculatorHandler(AsyncCalculator.Iface):
    @asyncio.coroutine
    def add(self, n1, n2):
        return 42

    @asyncio.coroutine
    def calculate(self, logid, work):
        return 0

    @asyncio.coroutine
    def zip(self):
        print('zip')


class AsyncSleepHandler(AsyncSleep.Iface):

    def __init__(self, loop):
        self._loop = loop

    @asyncio.coroutine
    def echo(self, message, delay):
        return asyncio.sleep(delay, result=message, loop=self._loop)

    @asyncio.coroutine
    def overflow(self, value):
        # simply return the value in OverflowResult
        return OverflowResult(value)