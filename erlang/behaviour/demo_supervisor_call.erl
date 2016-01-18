-module(demo_supervisor_call).

-export([
        start_link/2,
        tick/2
    ]).

start_link(Module, Args) ->
    io:format("startting with args ~p ~p ~n", [Module, Args]),
    tick(1, Args),
    %%proc_lib:start_link(?MODULE, tick, [self()]),
    io:format("startting with args ~p ~n", [Args]).

tick(Count, Args) ->
    io:format("ticking start ~n"),
    io:format("Args is ~p ~p~n", [Count, Args]),
    timer:sleep(1000),
    io:format("ticking stop ~n").
    %%tick(Count + 1, Args).


