class SingleSlotBuffer {
    private int value;
    private boolean hasValue = false;

    public synchronized void put(int x) {
        while (hasValue) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        value = x;
        hasValue = true;
        System.out.println("Produced: " + x);
        notify();
    }

    public synchronized int take() {
        while (!hasValue) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        int x = value;
        hasValue = false;
        System.out.println("  Consumed: " + x);
        notify();
        return x;
    }
}

class Producer extends Thread {
    private SingleSlotBuffer buffer;

    public Producer(SingleSlotBuffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            buffer.put(i);
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread {
    private SingleSlotBuffer buffer;

    public Consumer(SingleSlotBuffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            buffer.take();
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class ProducerConsumer {
    public static void main(String[] args) {
        SingleSlotBuffer buffer = new SingleSlotBuffer();
        Producer p = new Producer(buffer);
        Consumer c = new Consumer(buffer);
        p.start();
        c.start();
    }
}
