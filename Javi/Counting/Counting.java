package Javi.Counting;

import java.util.*;
import java.math.BigInteger;

public class Counting {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            Count.calculate(n);
        }

        sc.close();
    }
}

class Count {
    static Count staticCount = new Count();
    BigInteger c[] = new BigInteger[1001];
    int length;

    private Count() {
        c[0] = BigInteger.ZERO;
        c[1] = BigInteger.valueOf(2);
        c[2] = BigInteger.valueOf(5);
        c[3] = BigInteger.valueOf(13);
        length = 4;
    }

    public static void calculate(int n) {

        if (staticCount.c[n] == null) {
            for (int i = 4; i <= n; ++i) {
                staticCount.c[i] = staticCount.c[i - 1].multiply(staticCount.c[1]);
                staticCount.c[i] = staticCount.c[i].add(staticCount.c[i - 2]);
                staticCount.c[i] = staticCount.c[i].add(staticCount.c[i - 3]);
            }
        }
        System.out.println(staticCount.c[n]);

    }
}
