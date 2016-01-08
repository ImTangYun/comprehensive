-module(io_format_demo).

-export([print/0]).

print()->
    io:format("string:~s~n", ["str"]),
    io:format("char: ~c~n", [$a]),
    ok.
