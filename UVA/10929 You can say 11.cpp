import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s;
        BigInteger x;
        while(scanner.hasNext()) {
            s = scanner.next();
            if(s.equals("0")) break;
            x = new BigInteger(s);
            if(x.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO)) System.out.println(s + " is a multiple of 11.");
            else System.out.println(s + " is not a multiple of 11.");
        }
    }
}
