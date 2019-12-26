import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s;
        BigInteger m;
        int t = scanner.nextInt();
        int n, x;
        boolean ans;
        for(int i=0; i<t; i++) {
            s = scanner.next();
            m = new BigInteger(s);
            n = scanner.nextInt();
            ans = true;
            for(int j=0; j<n; j++) {
                x = scanner.nextInt();
                ans &= m.mod(BigInteger.valueOf(x)).equals(BigInteger.ZERO);
            }
            if(ans) System.out.println(s + " - Wonderful.");
            else System.out.println(s + " - Simple.");
        }
    }
}
