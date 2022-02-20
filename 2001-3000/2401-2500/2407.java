import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) throws IOException {
        int n, m;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        if (n < m * 2) {
            m = n - m;
        }

        BigInteger ans = new BigInteger("1");
        for (int i = n; i > n - m; i--) {
            ans = ans.multiply(new BigInteger(Integer.toString(i)));
        }
        for (int i = 2; i <= m; i++) {
            ans = ans.divide(new BigInteger(Integer.toString(i)));
        }
        System.out.println(ans);
    }
}

/*
 * 2407. 조합
 * https://www.acmicpc.net/problem/2407
 * 
 * 문제
 * nCm을 출력한다.
 * 
 * 입력
 * n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)
 * 
 * 출력
 * nCm을 출력한다.
 */