import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, ans;
        BigInteger x;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            x = fact(n);
            ans = 0;
            while(!x.equals(BigInteger.ZERO)) {
                ans += Integer.parseInt(x.mod(BigInteger.TEN).toString());
                x = x.divide(BigInteger.TEN);
            }
            System.out.println(ans);
        }

    }

    public static BigInteger fact(int n) {
        BigInteger x=BigInteger.ONE;
        for(int i=2; i<=n; i++) x = x.multiply(BigInteger.valueOf(i));
        return x;
    }
}
