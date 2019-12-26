import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigInteger[] de = new BigInteger[805];
        de[1] = BigInteger.ZERO;
        de[2] = BigInteger.ONE;
        for(int i=3; i<805; i++)
            de[i] = (de[i-1].add(de[i-2])).multiply(BigInteger.valueOf(i-1));

        Scanner scanner = new Scanner(System.in);
        int n;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            if(n == -1) break;
            System.out.println(de[n]);
        }
    }
}
