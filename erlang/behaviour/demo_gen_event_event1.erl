-module(demo_gen_event_event1).
-export([init/1,handle_event/2,handle_call/2,handle_info/2,
 terminate/2,code_change/3,format_status/2]).
 
%%-include("common.hrl").
-define(PRINT(Msg),io:format("~w ~w ~w:" ++ Msg ++ "~n",[self(),?MODULE,?LINE])).
-define(PRINT(Format,Msg),io:format("~w,~w ~w:" ++ Format ++ "~n",[self(),?MODULE,?LINE] ++ Msg)).
 
-record(state,{}).
 
init(Args) ->
?PRINT("Init Args:~p",[Args]),
{ok,#state{}}.
 
handle_event(log,State) ->
?PRINT("handel log"),
{ok,State};
 
handle_event(Msg,State) ->
?PRINT("Handle Event,Msg:~w",[Msg]),
{ok,State}.
 
handle_call(Request,State) ->
?PRINT("Handle Call:~w",[Request]),
{ok,ok,State}.
 
handle_info(Request,State) ->
?PRINT("Handle Info:~w",[Request]),
{ok,State}.
 
terminate(Reason,_State) ->
?PRINT("Terminate:~w",[Reason]),
ok.
 
code_change(_OldVsn,State,_Extra) ->
{ok,State}.
 
format_status(Op,State) ->
?PRINT("Format State:~w",Op),
{ok,State}.
