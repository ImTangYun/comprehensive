package pers.candy.learning.future;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;

public class FutureTest {

    public static void main(String[] args) throws InterruptedException,
            ExecutionException {

        FutureTask<String> futureTask = new FutureTask<String>(new RealData<String>(
                "hello data"));
        ExecutorService executorService = Executors.newCachedThreadPool();
        executorService.submit(futureTask);
        System.out.println(futureTask.get());
    }

}

class RealData<V> implements Callable<V> {

    String data;

    public RealData(String data) {
        this.data = data;
    }

    @SuppressWarnings("unchecked")
    @Override
    public V call() throws Exception {
        // TODO Auto-generated method stub
        Thread.sleep(5000);
        return (V) data;
    }

}