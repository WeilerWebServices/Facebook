if(!window.IG){window.IG={_client_id:null,_session:null,_userStatus:"unknown",_logging:false,_domain:{https_com:"https://instagram.com/",api:"http://api.instagram.com/"},getDomain:function(a){switch(a){case "https_com":return IG._domain.https_com;case "api":return IG._domain.api}},provide:function(a,d){return IG.copy(IG.create(a),d)},copy:function(a,d){for(var b in d)if(d.hasOwnProperty(b))if(typeof a[b]==="undefined")a[b]=d[b];return a},create:function(a,d){var b=window.IG,e=a?a.split("."):[],f=
e.length,g;for(g=0;g<f;g++){var h=e[g],i=b[h];if(!i){i=d&&g+1===f?d:{};b[h]=i}b=i}return b},guid:function(){return"f"+(Math.random()*1073741824).toString(16).replace(".","")},log:function(a){if(IG._logging)if(window.Debug&&window.Debug.writeln)window.Debug.writeln(a);else window.console&&window.console.log(a)},$:function(a){return document.getElementById(a)}};IG.provide("Array",{forEach:function(a,d){var b;if(a)if(Object.prototype.toString.apply(a)==="[object Array]"||!(a instanceof Function)&&typeof a.length===
"number")if(a.forEach)a.forEach(d);else{b=0;for(length=a.length;b<length;b++)d(a[b],b,a)}else for(b in a)a.hasOwnProperty(b)&&d(a[b],b,a)},join:function(a,d){var b="";IG.Array.forEach(a,function(e){b+=e+d});return b=b.substr(0,b.lastIndexOf(d))}});IG.provide("QS",{encode:function(a,d,b){d=d===undefined?"&":d;encoder=b===false?function(f){return f}:encodeURIComponent;var e=[];IG.Array.forEach(a,function(f,g){f!==null&&typeof f!=="undefined"&&e.push(encoder(g)+"="+encoder(f))});e.sort();return e.join(d)},
decode:function(a){a=a.split("&");var d={},b;for(b=0;b<a.length;b++)if((pair=a[b].split("=",2))&&pair[0])d[decodeURIComponent(pair[0])]=decodeURIComponent(pair[1]||"");return d}});IG.provide("Content",{_root:null,_hiddenRoot:null,_callbacks:{},append:function(a,d){if(!d)if(IG.Content._root)c=IG.Content._root;else{IG.Content._root=d=IG.$("ig-root");if(!d){IG.log('The "ig-root" div has not been created.');return}}if(typeof a==="string"){var b=document.createElement("div");d.appendChild(b).innerHTML=
a;return b}else return d.appendChild(a)},appendHidden:function(a){if(!IG.Content._hiddenRoot){var d=document.createElement("div");d.style.position="absolute";d.style.top="-10000px";d.style.width=d.style.height=0;IG.Content._hiddenRoot=IG.Content.append(d)}return IG.Content.append(a,IG.Content._hiddenRoot)},insertIframe:function(a){a.id=a.id||IG.guid();a.name=a.name||IG.guid();var d=IG.guid(),b=false,e=false;IG.Content._callbacks[d]=function(){if(b&&!e){e=true;a.onload&&a.onload(a.root.firstChild)}};
if(document.attachEvent){var f='<iframe id="'+a.id+'" name="'+a.name+'"'+(a.title?' title="'+a.title+'"':"")+(a.className?' class="'+a.className+'"':"")+' style="border:none;'+(a.width?"width:"+a.width+"px;":"")+(a.height?"height:"+a.height+"px;":"")+'" src="'+a.url+'" frameborder="0" scrolling="no" allowtransparency="true" onload="IG.Content._callbacks.'+d+'()"></iframe>';a.root.innerHTML='<iframe src="javascript:false" frameborder="0" scrolling="no" style="height:1px"></iframe>';b=true;window.setTimeout(function(){a.root.innerHTML=
f},0)}else{var g=document.createElement("iframe");g.id=a.id;g.name=a.name;g.onload=IG.Content._callbacks[d];g.scrolling="no";g.style.border="none";g.style.overflow="hidden";if(a.title)g.title=a.title;if(a.className)g.className=a.className;if(a.height)g.height=a.height;if(a.width)g.width=a.width;a.root.appendChild(g);b=true;g.src=a.url}}});IG.provide("JSON",{stringify:function(a){return window.Prototype&&Object.toJSON?Object.toJSON(a):JSON.stringify(a)},parse:function(a){return JSON.parse(a)},flatten:function(a){var d=
{},b;for(b in a)if(a.hasOwnProperty(b)){var e=a[b];if(typeof e==="string"&&b!==null)d[b]=e;else if(e!==null&&e!==undefined)d[b]=IG.JSON.stringify(e)}return d}});IG.provide("EventProvider",{subscribers:function(){if(!this._subscribersMap)this._subscribersMap={};return this._subscribersMap},subscribe:function(a,d){IG.log("Subscription to: "+a);var b=this.subscribers();if(b[a])b[a].push(d);else b[a]=[d]},unsubscribe:function(a,d){var b=this.subscribers()[a];IG.Array.forEach(b,function(e,f){if(e===d)b[f]=
null})},monitor:function(a,d){if(!d()){var b=this,e=function(){d.apply(d,arguments)&&b.unsubscribe(a,e)};this.subscribe(a,e)}},clear:function(a){delete this.subscribers()[a]},fire:function(){var a=Array.prototype.slice.call(arguments),d=a.shift();IG.log("Fire for: "+d);IG.Array.forEach(this.subscribers()[d],function(b){b&&b.apply(this,a)})}});IG.provide("Event",IG.EventProvider);IG.provide("XD",{_origin:null,_transport:null,_callbacks:{},init:function(){if(IG.XD._origin)IG.log('XD.init called with "XD._origin" already set. Returning.');
else if(window.addEventListener&&!window.attachEvent&&window.postMessage){IG.log('Using "postmessage" as XD transport.');IG.XD._origin=window.location.protocol+"//"+window.location.host+"/"+IG.guid();IG.XD.PostMessage.init();IG.XD._transport="postmessage"}else{IG.log('Using "fragment" as XD transport.');IG.XD._transport="fragment";IG.XD.Fragment._channelUrl=window.location.toString()}},resolveRelation:function(a){var d=a.split("."),b=window,e,f;f=0;for(num_relations=d.length;f<num_relations;f++){child=
d[f];if(child==="opener"||child==="parent"||child==="top")b=b[child];else if(e=/^frames\[['"]?([a-zA-Z0-9-_]+)['"]?\]$/.exec(child))b=b.frames[e[1]];else throw new SyntaxError("Malformed relation to resolve: "+a+", pt: "+child);}return b},handler:function(a,d){if(window.location.toString().indexOf(IG.XD.Fragment._magic)>0)return"javascript:false;//";var b=IG.getDomain("https_com")+"oauth/xd_proxy/#",e=IG.guid();if(IG.XD._transport==="fragment"){b=IG.XD.Fragment._channelUrl;var f=b.indexOf("#");if(f>
0)b=b.substr(0,f);b+=(b.indexOf("?")<0?"?":"&")+IG.XD.Fragment._magic+"#?=&"}IG.XD._callbacks[e]=a;return b+IG.QS.encode({cb:e,origin:IG.XD._origin,relation:d||"opener",transport:IG.XD._transport})},recv:function(a){if(typeof a==="string")a=IG.QS.decode(a);var d=IG.XD._callbacks[a.cb];delete IG.XD._callbacks[a.cb];d&&d(a)},PostMessage:{init:function(){var a=IG.XD.PostMessage.onMessage;window.addEventListener?window.addEventListener("message",a,false):window.attachEvent("onmessage",a)},onMessage:function(a){IG.XD.recv(a.data)}},
Fragment:{_magic:"ig_xd_fragment",checkAndDispatch:function(){var a=window.location.toString(),d=a.substr(a.indexOf("#")+1);if(a.indexOf(IG.XD.Fragment._magic)>0){IG.init=function(){};document.documentElement.style.display="none";IG.XD.resolveRelation(IG.QS.decode(d).relation).IG.XD.recv(d)}}}});IG.XD.Fragment.checkAndDispatch();IG.provide("",{ui:function(a,d){var b=IG.UIServer.prepareCall(a,d);if(b){var e=IG.UIServer[b.params.display];e?e(b):IG.log('"display" must be "popup"')}else IG.log('"prepareCall" failed to return options')}});
IG.provide("UIServer",{Methods:{},_active:{},_defaultCb:{},prepareCall:function(a,d){var b=a.method.toLowerCase(),e=IG.UIServer.Methods[b];b=IG.guid();IG.copy(a,{client_id:IG._client_id,access_token:IG._session&&IG._session.access_token||undefined});a.display=IG.UIServer.getDisplayMode(e,a);b={callback:d,id:b,size:e.size||{},url:e.url,params:a};if(e.transform){b=e.transform(b);if(!b){IG.log('Call to "transform" in "prepareCall" failed to return options');return}}e=IG.UIServer.getXdRelation(b.params.display);
b.params.redirect_uri=IG.UIServer._xdResult(b.callback,b.id,e,true);b.params=IG.JSON.flatten(b.params);if(e=IG.QS.encode(b.params))b.url+="?"+e;return b},getDisplayMode:function(a,d){if(d.display==="hidden")return"hidden";return"popup"},getXdRelation:function(a){if(a==="popup")return"opener"},popup:function(a){var d=typeof window.screenX!=="undefined"?window.screenX:window.screenLeft,b=typeof window.screenY!=="undefined"?window.screenY:window.screenTop,e=typeof window.outerHeight!=="undefined"?window.outerHeight:
document.documentElement.clientHeight-22,f=a.size.width,g=a.size.height;d=parseInt((d<0?window.screen.width+d:d)+((typeof window.outerWidth!=="undefined"?window.outerWidth:document.documentElement.clientWidth)-f)/2,10);b=parseInt(b+(e-g)/2.5,10);f="width="+f+",height="+g+",left="+d+",top="+b+",scrollbars=1,location=1,toolbar=0";IG.log("opening popup: "+a.id);IG.UIServer._active[a.id]=window.open(a.url,a.id,f)},hidden:function(a){a.className="IG_UI_Hidden";a.root=IG.Content.appendHidden("");IG.UIServer._insertIframe(a)},
_insertIframe:function(a){IG.UIServer._active[a.id]=false;IG.Content.insertIframe({url:a.url,root:a.root,className:a.className,width:a.size.width,height:a.size.height,onload:function(d){if(IG.UIServer._active.hasOwnProperty(a.id))IG.UIServer._active[a.id]=d}})},_xdRedirectUriHandler:function(a,d,b,e){if(e)IG.UIServer._defaultCb[d]=a;return IG.XD.handler(function(f){IG.UIServer._xdRecv(f,a)},b)+"&frame="+d},_xdRecv:function(a,d){var b=IG.UIServer._active[a.frame];try{b.close&&b.close()}catch(e){}delete IG.UIServer._active[a.frame];
delete IG.UIServer._defaultCb[a.frame];d(a)},_xdResult:function(a,d,b,e){return IG.UIServer._xdRedirectUriHandler(function(f){a&&f.result&&a(IG.JSON.parse(f.result))},d,b,e)}});IG.provide("",{getLoginStatus:function(a,d){if(IG._client_id){if(a)if(!d&&IG.Auth._loadState==="loaded"){a({status:IG._userStatus,session:IG._session});return}else IG.Event.subscribe("IG.loginStatus",a);if(!(!d&&IG.Auth._loadState==="loading")){IG.Auth._loadState="loading";IG.ui({method:"auth.status",display:"hidden"},function(b){IG.Auth._loadState=
"loaded";IG.Event.fire("IG.loginStatus",b);IG.Event.clear("IG.loginStatus")})}}else IG.log("IG.getLoginStatus() called before calling IG.init().")},login:function(a,d){IG.ui(IG.copy({display:"popup",method:"authorize"},d||{}),a)},logout:function(){IG.Auth.setSession()}});IG.provide("Auth",{setSession:function(a,d){var b=!IG._session&&a,e=IG._session&&!a,f=b||e||IG._session&&a&&IG._session.access_token!==a.access_token,g=d!==IG._userStatus,h={session:a,status:d};IG._session=a;IG._userStatus=d;f&&IG.Cookie.getEnabled()&&
IG.Cookie.set(a);g&&IG.Event.fire("auth.statusChange",h);b&&IG.Event.fire("auth.login",h);e&&IG.Event.fire("auth.logout",h);f&&IG.Event.fire("auth.sessionChange",h);return h},xdHandler:function(a,d,b,e,f,g){return IG.UIServer._xdRedirectUriHandler(IG.Auth.xdResponseWrapper(a,f,g),d,b,e)},xdResponseWrapper:function(a,d,b){return function(e){try{b=IG.JSON.parse(e.session||null);b.scope=IG.JSON.parse(e.scope||null)}catch(f){}if(b)d="connected";var g=IG.Auth.setSession(b||null,d),h=["code","error","error_reason",
"error_description"];e&&IG.Array.forEach(h,function(i){g[i]=e[i]||null});a&&a(g)}}});IG.provide("UIServer.Methods",{authorize:{size:{width:627,height:326},url:IG.getDomain("https_com")+"oauth/authorize/",transform:function(a){if(IG._client_id){if(IG._session){var d=false;IG.Array.forEach(a.params.scope,function(b){if(IG._session.scope.indexOf(b)===-1)d=true});if(!d){IG.log("IG.login() called when user is already connected.");if(a.callback){a.callback({status:IG._userStatus,session:IG._session});return}}}a.callback=
IG.Auth.xdResponseWrapper(a.callback);if(a.params.scope)a.params.scope=a.params.scope.join(" ");IG.copy(a.params,{response_type:"token"});return a}else IG.log("IG.login() called before claling IG.init().")}},"auth.status":{url:IG.getDomain("https_com")+"oauth/login_status/",transform:function(a){var d=a.callback;delete a.callback;IG.copy(a.params,{no_session:IG.Auth.xdHandler(d,a.id,"parent",false,"notConnected"),no_user:IG.Auth.xdHandler(d,a.id,"parent",false,"unknown"),ok_session:IG.Auth.xdHandler(d,
a.id,"parent",false,"connected")});return a}}});IG.provide("Cookie",{_domain:null,_enabled:false,setEnabled:function(a){IG.Cookie._enabled=a},getEnabled:function(){return IG.Cookie._enabled},load:function(){var a=document.cookie.match("\\bigs_"+IG._client_id+'="([^;]*)\\b'),d;if(a){d=IG.QS.decode(a[1]);if(d.expires)d.expires=parseInt(d.expires,10);IG.Cookie._domain=d.base_domain}return d},setRaw:function(a,d,b){document.cookie="igs_"+IG._client_id+'="'+a+'"'+(a&&d===0?"":"; expires="+(new Date(d*
1E3)).toGMTString())+"; path=/"+(b?"; domain=."+b:"");IG.Cookie._domain=b},set:function(a){a?IG.Cookie.setRaw(IG.QS.encode(a),a.expires,a.base_domain):IG.Cookie.clear()},clear:function(){IG.Cookie.setRaw("",0,IG.Cookie._domain)}});IG.provide("",{init:function(a){a=IG.copy(a||{},{logging:false,check_status:true});IG._client_id=a.client_id;IG._logging=a.logging||typeof a.logging==="undefined"&&window.location.toString().indexOf("ig_debug=1")>0;IG.XD.init();if(IG._client_id){IG.Cookie.setEnabled(a.cookie);
a.session=a.session||a.cookie&&IG.Cookie.load();IG.Auth.setSession(a.session);a.check_status&&IG.getLoginStatus()}}});window.setTimeout(function(){if(window.igAsyncInit&&!window.igAsyncInit.hasRun){window.igAsyncInit.hasRun=true;igAsyncInit()}},0)};