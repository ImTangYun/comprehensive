-module(record_demo).
-export([test/0]).

-record(ctx, {v1, v2, v3}).

test()->
    Ctx = #ctx{},
    Ctx1 = Ctx#ctx{
        v1 = "v1",
        v2 = "v2",
        v3 = ["v3"]
    },
    io:format("--~s--~n", Ctx1#ctx.v3).
