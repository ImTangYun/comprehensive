-module(demo_supervisor).

-behaviour(supervisor).

-export([
        start_link/0,
        init/1
    ]).

start_link() ->
    supervisor:start_link({local,?MODULE}, ?MODULE, []).

init([]) ->
    {ok, {{simple_one_for_one, 1, 60},
        [{id, {demo_supervisor_call, start_link, [hello, ok]},
                permanent, 5000, worker, [demo_supervisor_call]}]}}.
