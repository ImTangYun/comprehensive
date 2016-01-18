#Usage:
erlc *.erl  
erl  
1>Pid = spawn(fun demo_spawn:loop/0).  
<0.33.0>  
2> Pid ! {task2, " data of task 2"}.  
received task2 data is " data of task 2"  
{task2," data of task 2 "}  
3> demo_spawn:msg_sender(Pid).  
received task1 data is "task1"  
received task2 data is "task2"  
received task3 data is "task3"  
received task4 data is "task4"  
...  
...   

