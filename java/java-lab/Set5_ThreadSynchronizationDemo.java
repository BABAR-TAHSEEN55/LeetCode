class Counter {
    private int value;

    synchronized void increment() {
        value++;
    }

    int getValue() {
        return value;
    }
}

class IncrementTask implements Runnable {
    private final Counter counter;

    IncrementTask(Counter counter) {
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}

public class Set5_ThreadSynchronizationDemo {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        Thread firstThread = new Thread(new IncrementTask(counter), "FirstThread");
        Thread secondThread = new Thread(new IncrementTask(counter), "SecondThread");

        firstThread.start();
        secondThread.start();

        firstThread.join();
        secondThread.join();

        System.out.println("Final counter value: " + counter.getValue());
    }
}
