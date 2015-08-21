package pers.candy.learning.executor;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class ThreadPoolExecutor extends AbstractExecutorService {

    private int corePoolSize;
    private int maximumPoolSize;
    private long keepAliveTime;
    private TimeUnit unit;
    BlockingQueue<Runnable> workQueue;
    private int threadNum = 0;

    public ThreadPoolExecutor(int corePoolSize, int maximumPoolSize,
            long keepAliveTime, TimeUnit unit, BlockingQueue<Runnable> workQueue) {
        this.corePoolSize = corePoolSize;
        this.maximumPoolSize = maximumPoolSize;
        this.keepAliveTime = keepAliveTime;
        this.unit = unit;
        this.workQueue = workQueue;
    }

    @Override
    public void execute(Runnable runnable) throws InterruptedException {
        if (runnable == null) {
            throw new NullPointerException("null ptr");
        }
        if (threadNum < corePoolSize) {
            Thread t = new TaskProcessor(runnable, workQueue);
            if (t != null) {
                t.start();
                ++threadNum;
            }
        } else {
            workQueue.put(runnable);
        }
    }
    
    public int getThreadNum() {
        return threadNum;
    }

    public int getCorePoolSize() {
        return corePoolSize;
    }

    public void setCorePoolSize(int corePoolSize) {
        this.corePoolSize = corePoolSize;
    }

    public int getMaximumPoolSize() {
        return maximumPoolSize;
    }

    public void setMaximumPoolSize(int maximumPoolSize) {
        this.maximumPoolSize = maximumPoolSize;
    }

    public long getKeepAliveTime() {
        return keepAliveTime;
    }

    public void setKeepAliveTime(long keepAliveTime) {
        this.keepAliveTime = keepAliveTime;
    }

    public TimeUnit getUnit() {
        return unit;
    }

    public void setUnit(TimeUnit unit) {
        this.unit = unit;
    }

    public BlockingQueue<Runnable> getWorkQueue() {
        return workQueue;
    }

    public void setWorkQueue(BlockingQueue<Runnable> workQueue) {
        this.workQueue = workQueue;
    }

}
