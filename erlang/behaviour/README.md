gen_server行为模式使用：

必须实现的接口：
code_change/3,handle_call/3,handle_cast/2,handle_info/2,init/1,terminate/2
固定实现的接口：
start/0, stop/0
start() ->
    gen_server:start_link({local, ?MODULE}, ?MODULE, [], []).

stop() ->
    gen_server:call(?MODULE, stop).

InternalData是一个全局变量，这里对它进行初始化
init([]) ->
    {ok, InternalData}
例子：
init([]) ->
    {ok, "hello"}
结果：InternalData的值为"hello"

handle_call/3获得和改变InternalData的方式:
handle_call({test, Data}, _From, InternalData) ->
    NewInternalData = anotherdata,
    {reply, ResponseData, InternalData}. %%此时调用handle_call获得数据ResponseData, InternalData改变为NewInternalData
多个rpc调用需要多个handle_call,那么我们用原子区分它们：

resp1(Data1) ->
    gen_server:call(?MODULE, {test1, Data1}).
resp2(Data2) ->
    gen_server:call(?MODULE, {test2, Data2}).
resp3(Data3, Data4) ->
    gen_server:call(?MODULE, {test3, Data3, Data4}).
handle_call({test1, Data1}, _From, InitData) ->
    ...
    {reply, ResponseData1, NewInternalData1};
handle_call({test2, Data2}, _From, InitData) ->
    ...
    {reply, ResponseData2, NewInternalData2};
handle_call({test3, Data3, Data4}, _From, InitData) ->
    ...
    {reply, ResponseData3, NewInternalData3}.

handle_call/3与handle_cast/3主要区别是，前者是同步的调用，会阻塞，后者是异步调用，非阻塞

demo_gen_server使用：
1.编译代码(erlc *.erl)
2.erl
3.>demo_gen_server:start().
4.>demo_gen_server:response().
demo_gen_server_cache使用：
1.编译代码（erlc *.erl）
2.erl
3.>demo_gen_server_cache:start().
4.>demo_gen_server_cache:insert("candy", "a handsome man").
5.>demo_gen_server_cache:find("candy").
6.>demo_gen_server_cache:delete("candy").
7.>demo_gen_server_cache:delete("candy").


