import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int maxn = 50;
        BigInteger[][] C = new BigInteger[maxn+1][maxn+1];

        for(int n=0; n<=maxn; n++) {
            C[n][0] = C[n][n] = BigInteger.ONE;
            for(int k=1; k<n; k++) {
                C[n][k] = C[n-1][k-1].add(C[n-1][k]);
            }
        }

        HashMap<BigInteger, Integer> Cat = new HashMap<>();
        for(int i=1; i<25; i++) {
            Cat.put(C[2*i][i].divide(BigInteger.valueOf(i+1)), i);
        }

        Scanner scanner = new Scanner(System.in);
        long x;
        while(scanner.hasNextLong()) {
            x = scanner.nextLong();
            System.out.println(Cat.get(BigInteger.valueOf(x)));
        }
    }
}
