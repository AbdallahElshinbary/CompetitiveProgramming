import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigInteger[] fib = new BigInteger[4005];
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(1);
        for(int i=2; i<4002; i++) {
            fib[i] = fib[i-1].add(fib[i-2]);
        }

        Scanner scanner = new Scanner(System.in);
        int n;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            if(n == 0) break;
            System.out.println(fib[n*2 - 1]);
        }
    }
}
