import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       BigInteger[] fib = new BigInteger[2000];
       BigInteger[] sol = new BigInteger[2000];

       fib[0] = BigInteger.valueOf(1);
       fib[1] = BigInteger.valueOf(1);
       sol[0] = BigInteger.valueOf(0);
       sol[1] = BigInteger.valueOf(1);
       BigInteger x = BigInteger.valueOf(2), shift;

       for(int i=2; i<1500; i++) {
           fib[i] = fib[i-1].add(fib[i-2]);
           shift = fib[i].divide(BigInteger.valueOf(2));
           if(fib[i].mod(BigInteger.valueOf(2)).equals(BigInteger.valueOf(0))) {
               shift = shift.subtract(BigInteger.valueOf(1));
           }
           sol[i] = x.add(shift);
           x = x.add(fib[i]);
       }

       int t=1, n;
       Scanner scanner = new Scanner(System.in);
       while (scanner.hasNextInt()) {
           n = scanner.nextInt();
           if(n == 0) break;
           System.out.println("Set " + t++ + ":\n" + sol[n-1]);
       }
       scanner.close();
    }
}
