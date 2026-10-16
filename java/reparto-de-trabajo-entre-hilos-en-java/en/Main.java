import java.io.IOException;

public class Main {

    // Shared state: only touched through synchronized methods.
    static class Accumulator {
        private long sum;
        private int peaks;

        synchronized void contribute(long s, int p) {
            sum += s;
            peaks += p;
        }

        synchronized long sum() {
            return sum;
        }

        synchronized int peaks() {
            return peaks;
        }
    }

    // Each worker processes the interval [begin, end) of the array.
    static class Worker extends Thread {
        private final int[] data;
        private final int begin;
        private final int end;
        private final int threshold;
        private final Accumulator acc;
        private long localSum;
        private int localPeaks;

        Worker(int[] data, int begin, int end, int threshold, Accumulator acc) {
            this.data = data;
            this.begin = begin;
            this.end = end;
            this.threshold = threshold;
            this.acc = acc;
        }

        @Override
        public void run() {
            long s = 0;
            int p = 0;
            for (int i = begin; i < end; i++) {
                s += data[i];
                if (data[i] > threshold) {
                    p++;
                }
            }
            localSum = s;
            localPeaks = p;
            acc.contribute(s, p); // a single critical section per thread
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        String[] tok = new String(System.in.readAllBytes()).trim().split("\\s+");
        int n = Integer.parseInt(tok[0]);
        int k = Integer.parseInt(tok[1]);
        int threshold = Integer.parseInt(tok[2]);
        int[] data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = Integer.parseInt(tok[3 + i]);
        }

        Accumulator acc = new Accumulator();
        Worker[] workers = new Worker[k];
        int base = n / k;
        int remainder = n % k;
        int pos = 0;
        for (int h = 0; h < k; h++) {
            int size = base + (h < remainder ? 1 : 0);
            workers[h] = new Worker(data, pos, pos + size, threshold, acc);
            pos += size;
        }

        for (Worker w : workers) {
            w.start();
        }
        for (Worker w : workers) {
            w.join();
        }

        StringBuilder sb = new StringBuilder();
        for (int h = 0; h < k; h++) {
            Worker w = workers[h];
            sb.append("Thread ").append(h).append(": [").append(w.begin).append(", ").append(w.end)
              .append(") sum=").append(w.localSum).append(" peaks=").append(w.localPeaks).append('\n');
        }
        sb.append("Total: sum=").append(acc.sum())
          .append(" peaks=").append(acc.peaks()).append('\n');
        System.out.print(sb);
    }
}
