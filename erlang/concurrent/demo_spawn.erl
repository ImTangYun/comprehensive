-module(demo_spawn).
-export([
        loop/0,
        msg_sender/1
    ]).

loop() ->
    receive
        {task1, Data} ->
            io:format("received task1 data is ~p~n", [Data]),
            loop();
        {task2, Data} ->
            io:format("received task2 data is ~p~n", [Data]),
            loop();
        {task3, Data} ->
            io:format("received task3 data is ~p~n", [Data]),
            loop();
        {task4, Data} ->
            io:format("received task4 data is ~p~n", [Data]),
            loop();
        Other ->
            io:format("don't understand cmd! ~p~n", [Other]),
            loop()
    end.

msg_sender(Pid) ->
    Pid ! {task1, "task1"},
    Pid ! {task2, "task2"},
    Pid ! {task3, "task3"},
    Pid ! {task4, "task4"},
    timer:sleep(1000),
    msg_sender(Pid).
