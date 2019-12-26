import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        BigInteger x;
        int[] freq = new int[10];
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            if(n == 0) break;
            x = fact(n);
            for(int i=0; i<10; i++) freq[i]=0;
            while(!x.equals(BigInteger.ZERO)) {
                freq[Integer.parseInt(x.mod(BigInteger.TEN).toString())]++;
                x = x.divide(BigInteger.TEN);
            }
            System.out.printf("%d! --\n", n);
            for(int i=0; i<10; i++) {
                if(i == 0) System.out.print("   ");
                else if(i == 5) System.out.print("\n   ");
                else System.out.print("    ");
                System.out.printf("(%d)%5d",i,freq[i]);
            }
            System.out.println();
        }
    }

    public static BigInteger fact(int n) {
        BigInteger x=BigInteger.ONE;
        for(int i=2; i<=n; i++) x = x.multiply(BigInteger.valueOf(i));
        return x;
    }
}
