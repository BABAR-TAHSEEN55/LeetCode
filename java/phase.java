
class Queue {
    private int item;
    private boolean available = false;

    public synchronized int consume() {
        while (!available) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        available = false;
        notify();
        System.out.println("Consumed: " + item);
        return item;
    }

    public synchronized void produce(int newItem) {
        while (available) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.item = newItem;
        available = true;
        notify();
        System.out.println("Produced: " + item);
    }
}

class Producer extends Thread {
    private Queue queue;

    Producer(Queue queue) {
        this.queue = queue;
    }

    public void run() {
        try {
            for (int i = 0; i <= 5; i++) {
                queue.produce(i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Consumer extends Thread {
    private Queue queue;

    Consumer(Queue queue) {
        this.queue = queue;
    }

    public void run() {
        try {
            for (int i = 0; i <= 5; i++) {
                queue.consume();
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String args[]) {
        Queue queue = new Queue();
        Producer producer = new Producer(queue);
        Consumer consumer = new Consumer(queue);

        producer.start();
        consumer.start();

        try {
            producer.join();
            consumer.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
