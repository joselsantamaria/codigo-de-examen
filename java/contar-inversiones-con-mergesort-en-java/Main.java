import java.io.*;

public class Main {

    // Ordena a[lo, hi) y devuelve el numero de parejas desordenadas de ese tramo.
    static long contar(int[] a, int[] aux, int lo, int hi) {
        if (hi - lo <= 1) {
            return 0;
        }
        int mid = (lo + hi) >>> 1;
        long inv = contar(a, aux, lo, mid) + contar(a, aux, mid, hi);
        int i = lo, j = mid, k = lo;
        while (i < mid && j < hi) {
            if (a[i] <= a[j]) {
                aux[k++] = a[i++];
            } else {
                inv += mid - i;
                aux[k++] = a[j++];
            }
        }
        while (i < mid) {
            aux[k++] = a[i++];
        }
        while (j < hi) {
            aux[k++] = a[j++];
        }
        System.arraycopy(aux, lo, a, lo, hi - lo);
        return inv;
    }

    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(
                new BufferedReader(new InputStreamReader(System.in)));
        int n = 0;
        if (st.nextToken() != StreamTokenizer.TT_EOF) {
            n = (int) st.nval;
        }
        int[] a = new int[n];
        for (int idx = 0; idx < n; idx++) {
            st.nextToken();
            a[idx] = (int) st.nval;
        }
        System.out.println(contar(a, new int[n], 0, n));
    }
}
