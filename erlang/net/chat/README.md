1，启动server 
Java代码  收藏代码 
Eshell> chat_server:start(9999).   
 
 
2，启动send和recv两个client进程  
Java代码  收藏代码 
$$ client1   
Eshell> chat_send_client:start("localhost", 9999).   
Eshell> chat_recv_client:start("localhost", 9999).   
$$ client2   
Eshell> chat_send_client:start("localhost", 9999).   
Eshell> chat_recv_client:start("localhost", 9999).   
  
  
3，交互过程  
Java代码  收藏代码  
%% client1/send    
Input you msg:我囧    
%% client2/send    
Input you msg:你囧啥?    
%% client1、2/recv    
Received msg: "我囧\n"    
Received msg: "你囧啥?\n"    
