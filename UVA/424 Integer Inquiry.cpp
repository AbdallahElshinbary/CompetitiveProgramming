import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n;
        BigInteger x = BigInteger.ZERO;
        while(scanner.hasNext()) {
            n = scanner.next();
            if(n.equals("0")) break;
            x = x.add(new BigInteger(n));
        }
        System.out.println(x);
    }
}
