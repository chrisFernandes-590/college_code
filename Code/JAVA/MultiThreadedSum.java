import java.util.*;

class SumWorker extends Thread {
    private List<Integer> part;
    private long partialSum = 0;

    public SumWorker(List<Integer> part) {
        this.part = part;
    }

    public void run() {
        for (int x : part) partialSum += x;
    }

    public long getPartialSum() {
        return partialSum;
    }
}

public class MultiThreadedSum {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= 1000; i++) numbers.add(i);

        int threadCount = 4;
        List<SumWorker> workers = new ArrayList<>();

        int size = numbers.size();
        int chunk = size / threadCount;

        for (int i = 0; i < threadCount; i++) {
            int start = i * chunk;
            int end = (i == threadCount - 1) ? size : start + chunk;
            List<Integer> sub = numbers.subList(start, end);
            SumWorker worker = new SumWorker(sub);
            workers.add(worker);
            worker.start();
        }

        long totalSum = 0;
        for (SumWorker w : workers) {
            try {
                w.join();
            } catch (InterruptedException e) {}
            totalSum += w.getPartialSum();
        }

        System.out.println("Total Sum: " + totalSum);
    }
}
