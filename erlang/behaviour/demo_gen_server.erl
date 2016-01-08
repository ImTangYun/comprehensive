-module(demo_gen_server).
-behaviour(gen_server).

-export([
        start/0,
        stop/0,
        response/1,
        response1/1,
        test/1
    ]).
-export([
        code_change/3,handle_call/3,handle_cast/2,handle_info/2,init/1,terminate/2
    ]).

start() ->
    gen_server:start_link({local, ?MODULE}, ?MODULE, [], []).

stop() ->
    gen_server:call(?MODULE, stop).

response(Data) ->
    gen_server:call(?MODULE, {test, Data}).

response1(Data) ->
    gen_server:call(?MODULE, {test1, Data}).
init([]) ->
    IniternalData = "inited",
    {ok, IniternalData}.

handle_call({test, Data}, _From, IniternalData) ->
    io:format("call handle_call, from ~p, IniternalData ~p ~n", [_From, IniternalData]),
    {ok, RespData} = test(Data),
    NewIniternalData = "call test",
    {reply, RespData, NewIniternalData};

handle_call({test1, Data}, _From, IniternalData) ->
    io:format("call handle_call, from ~p, InitData ~p ~n", [_From, IniternalData]),
    {ok, RespData} = test(Data),
    NewIniternalData = "called test1",
    {reply, RespData, NewIniternalData}.
test(Data) ->
    io:format("recv data ~p~n", [Data]),
    {ok, Data}.
handle_cast(_Msg, State) ->
    {noreply, State}.
handle_info(_Info, State) ->
    {noreply, State}.
code_change(_OldVsn, State, Extra) ->
    {ok, State}.
terminate(_Reason, State) ->
    ok.
