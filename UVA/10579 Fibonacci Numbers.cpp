/* package whatever; // don't place package name! */

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNextInt()) {
            int n = scanner.nextInt();
            System.out.println(getFib(n));
        }
    }

    public static BigInteger getFib(int n) {
        BigInteger[] arr = new BigInteger[n+1];
        arr[0] = new BigInteger("1");
        arr[1] = new BigInteger("1");
        for(int i=2; i<n; i++) {
            arr[i] = arr[i-1].add(arr[i-2]);
        }
        return arr[n-1];
    }
}
