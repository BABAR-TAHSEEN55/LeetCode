class NumberThread extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(getName() + " prints number: " + i);
        }
    }
}

class AlphabetTask implements Runnable {
    @Override
    public void run() {
        for (char letter = 'A'; letter <= 'E'; letter++) {
            System.out.println(Thread.currentThread().getName() + " prints letter: " + letter);
        }
    }
}

public class Set4B_ThreadDemo {
    public static void main(String[] args) throws InterruptedException {
        NumberThread threadClassExample = new NumberThread();
        threadClassExample.setName("ThreadClass");

        Thread runnableExample = new Thread(new AlphabetTask(), "RunnableThread");

        threadClassExample.start();
        runnableExample.start();

        threadClassExample.join();
        runnableExample.join();
    }
}
