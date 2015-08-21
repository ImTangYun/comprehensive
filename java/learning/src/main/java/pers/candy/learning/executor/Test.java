package pers.candy.learning.executor;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class Test {

    public static void main(String[] args) throws InterruptedException {

        BlockingQueue<Runnable> workQueue = new ArrayBlockingQueue<>(10000);
        ThreadPoolExecutor executor = new ThreadPoolExecutor(3, 100, 100,
                TimeUnit.MICROSECONDS, workQueue);
        for (int i = 0; i < 1000; ++i) {
            executor.execute(new MyTask(i));
            System.out.println("thread num:" + executor.getThreadNum());
        }
        while (true) {
            Thread.sleep(100);
        }
    }

}

class MyTask implements Runnable {

    int num;

    public MyTask(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("thread num " + num + " started");
        try {
            Thread.sleep(4000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("thread num " + num + " stopped");
    }
}
