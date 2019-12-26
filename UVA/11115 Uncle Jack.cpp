import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int x,y;
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            x = scanner.nextInt();
            y = scanner.nextInt();
            if(x == 0) break;
            System.out.println(BigInteger.valueOf(x).pow(y));
        }
    }
}
