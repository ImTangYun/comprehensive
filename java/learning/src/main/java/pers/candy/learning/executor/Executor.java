package pers.candy.learning.executor;

public interface Executor {

    public void execute(Runnable runnable) throws InterruptedException;
}
