import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int maxn = 2000;
        BigInteger[][] C = new BigInteger[maxn+1][maxn+1];

        for(int n=0; n<=maxn; n++) {
            C[n][0] = C[n][n] = BigInteger.ONE;
            for(int k=1; k<n; k++) {
                C[n][k] = C[n-1][k-1].add(C[n-1][k]);
            }
        }

        Scanner scanner = new Scanner(System.in);
        int x;
        while(scanner.hasNextInt()) {
            x = scanner.nextInt();
            System.out.println(C[2*x][x].divide(BigInteger.valueOf(x+1)));
        }
    }
}
