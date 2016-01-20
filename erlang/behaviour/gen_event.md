#Usage of gen_event_demo:
[tangyun@leoss_stanchion behaviour]$ erl  
Erlang R15B03 (erts-5.9.3.1) [source] [64-bit] [smp:8:8] [async-threads:0] [hipe] [kernel-poll:false]  
  
Eshell V5.9.3.1  (abort with ^G)  
1> gen_event:start({local, test_event}).  
{ok,<0.33.0>}  
2> gen_event:add_handler(test_event, demo_gen_event_event1,"test add event").  
<0.33.0>,demo_gen_event_event1 12:Init Args:"test add event"  
ok  
3> gen_event:add_handler(test_event, demo_gen_event_event2,"test add event").  
<0.33.0>,demo_gen_event_event2 13:Init Args:[116,101,115,116,32,97,100,100,32,101,118,101,110,116]  
ok  
4> gen_event:notify(test_event, log).  
<0.33.0> demo_gen_event_event2 17:handel log  
ok  
<0.33.0> demo_gen_event_event1 16:handel log  
5> gen_event:notify(test_event,crash).  
<0.33.0> demo_gen_event_event2 22:handel crash  
ok  
<0.33.0>,demo_gen_event_event2 39:Terminate:{error,{'EXIT',{{badmatch,2},[{demo_gen_event_event2,handle_event,2,[{file,[100,101,109,111,95,103,101,110,95,101,118,101,110,116,95,101,118,101,110,116,50,46,101,114,108]},{line,23}]},{gen_event,server_update,4,[{file,[103,101,110,95,101,118,101,110,116,46,101,114,108]},{line,504}]},{gen_event,server_notify,4,[{file,[103,101,110,95,101,118,101,110,116,46,101,114,108]},{line,486}]},{gen_event,handle_msg,5,[{file,[103,101,110,95,101,118,101,110,116,46,101,114,108]},{line,248}]},{proc_lib,init_p_do_apply,3,[{file,[112,114,111,99,95,108,105,98,46,101,114,108]},{line,227}]}]}}}  
<0.33.0>,demo_gen_event_event1 20:Handle Event,Msg:crash  
6>   
=ERROR REPORT==== 20-Jan-2016::11:04:46 ===  
** gen_event handler demo_gen_event_event2 crashed.  
** Was installed in test_event  
** Last event was: crash  
** When handler state == {state}  
** Reason == {{badmatch,2},  
              [{demo_gen_event_event2,handle_event,2,  
                                      [{file,"demo_gen_event_event2.erl"},  
                                       {line,23}]},  
               {gen_event,server_update,4,[{file,"gen_event.erl"},{line,504}]},  
               {gen_event,server_notify,4,[{file,"gen_event.erl"},{line,486}]},  
               {gen_event,handle_msg,5,[{file,"gen_event.erl"},{line,248}]},  
               {proc_lib,init_p_do_apply,3,  
                         [{file,"proc_lib.erl"},{line,227}]}]}  
  
6> gen_event:notify(test_event, log).   
<0.33.0> demo_gen_event_event1 16:handel log  
ok  

