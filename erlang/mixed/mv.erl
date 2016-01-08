-module(mv).

-export([
    mv/2
    ]).

%% copy file Src and Write it to file Dst
mv(Src, Dst) ->
    {ok, Input} = file:open(Src, [read]),
    {ok, Output} = file:open(Dst, [write]),
    FileSize = filelib:file_size(Src),
    foo(Input, Output, FileSize),
    file:close(Input),
    file:close(Output).
foo(Input, Output, LeftSize) when LeftSize < 10000 ->
    {ok, Content} = file:read(Input, LeftSize),
    %file:write(Output, Content),
    io:format(Output, "~s", [Content]),
    {ok, last};
foo(Input, Output, LeftSize) ->
    Chunk = 10000,
    LeftSize1 = LeftSize - Chunk,
    {ok, Content} = file:read(Input, Chunk),
    file:write(Output, Content),
    %io:format(Output, "~w", [Content]),
    foo(Input, Output, LeftSize1).



