package pers.candy.learning.executor;

public interface ExecutorService extends Executor {

    public void submit();
    
    public void invokeAll();
    
    public void invokeAny();
    
    public void shutDown();
}
