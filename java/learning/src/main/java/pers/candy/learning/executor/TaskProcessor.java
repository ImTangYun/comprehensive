package pers.candy.learning.executor;

import java.util.concurrent.BlockingQueue;

public class TaskProcessor extends Thread {

    private Runnable runnable;
    private BlockingQueue<Runnable> workQueue;
    
    public TaskProcessor(Runnable runnable, BlockingQueue<Runnable> workQueue) {
        this.runnable = runnable;
        this.workQueue = workQueue;
    }
    
    @Override
    public void run() {
        for ( ; ; ) {
            if (runnable != null) {
                runnable.run();
            }
            try {
                runnable = workQueue.take();
                if (runnable != null) {
                    runnable.run();
                    runnable = null;
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
