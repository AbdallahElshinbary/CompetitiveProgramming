import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            System.out.println(n + "!");
            System.out.println(fact(n));
        }

    }

    public static BigInteger fact(int n) {
        BigInteger x=BigInteger.ONE;
        for(int i=2; i<=n; i++) x = x.multiply(BigInteger.valueOf(i));
        return x;
    }
}
