-module(list_append_demo).

-export([list_append/0]).

list_append()->
    L1 = "l1",
    L2 = "l2",
    Ret = L1 ++ L2,
    io:format("l1 ++ l2 is: ~s~s~n", [Ret]).
