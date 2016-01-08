-module(demo_gen_server_cache).
-behaviour(gen_server).

-export([
        start/0,
        stop/0,
        insert/2,
        find/1,
        delete/1
    ]).
-export([
        code_change/3,handle_call/3,handle_cast/2,handle_info/2,init/1,terminate/2
    ]).

start() ->
    gen_server:start_link({local, ?MODULE}, ?MODULE, [], []).

stop() ->
    gen_server:call(?MODULE, stop).

insert(Key, Value) ->
    gen_server:call(?MODULE, {insert, Key, Value}).

find(Key) ->
    gen_server:call(?MODULE, {find, Key}).

delete(Key) ->
    gen_server:call(?MODULE, {delete, Key}).

init([]) ->
    IniternalData = dict:new(),
    {ok, IniternalData}.

handle_call({insert, Key, Value}, _From, IniternalData) ->
    io:format("storing Data[~p:~p]~n", [Key, Value]),
    NewIniternalData = dict:store(Key, Value, IniternalData),
    {reply, ok, NewIniternalData};

handle_call({find, Key}, _From, IniternalData) ->
    io:format("finding Key:~p~n", [Key]),
    RespData = dict:find(Key, IniternalData),
    case RespData of
        {ok, _} ->
            {reply, RespData, IniternalData};
        Error ->
            {reply, Error, IniternalData}
    end;
            
handle_call({delete, Key}, _From, IniternalData) ->
    io:format("deleting Key:~p~n", [Key]),
    NewIniternalData = dict:erase(Key, IniternalData),
    case NewIniternalData of
        error ->
            {reply, ok, IniternalData};
        _ ->
        {reply, ok, NewIniternalData}
    end.

handle_cast(_Msg, State) ->
    {noreply, State}.
handle_info(_Info, State) ->
    {noreply, State}.
code_change(_OldVsn, State, Extra) ->
    {ok, State}.
terminate(_Reason, State) ->
    ok.
