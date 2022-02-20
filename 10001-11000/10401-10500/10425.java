import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{

    static BigInteger fib[] = new BigInteger[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();

        fibonacci();

        for(int i=0;i<t;i++){
            String num = br.readLine();
            if(num == "1"){
                result.append(2).append("\n");
            }
            else {
                BigInteger target = new BigInteger(num);
                result.append(binarySearch(target)).append("\n");
            }
        }

        System.out.println(result);
    }

    public static void fibonacci() {
        fib[0] = new BigInteger("0"); fib[1] = new BigInteger("1");
        for(int i=2;i<=100000;i++){
            fib[i] = fib[i-1].add(fib[i-2]);
        }
    }

    public static int binarySearch(BigInteger target) {
        int l = 0;
        int r = 100000;
        
        while(l <= r) {
            int mid = (l+r)/2;
            int compareTo = fib[mid].compareTo(target);
            if(compareTo == 1){
                r = mid - 1;
            }
            else if(compareTo == 0){
                return mid;
            }
            else {
                l = mid + 1;
            }
            //target < mid : 1
            //target == mid : 0
            //target > mid : -1
        }
        return l;
    }
}



/*
10425. 피보나치 인버스
https://www.acmicpc.net/problem/10425

문제
 

\[F_n =  \begin{cases} 0  & \text{if n = 0;} \\ 1   & \text{if n = 1;} \\ F_{n-1} + F_{n-2}   & \text{if n > 1.} \end{cases}\] 

피보나치 수는 수학에서 위의 점화식으로 정의되는 수열이다. 피보나치 수는 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다. n = 0, 1,...에 해당하는 피보나치 수는 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946… 이다.

프로그래밍 실습에서 문제 중 n을 입력 받았을 때 Fn의 값을 출력하는 문제가 자주 등장한다. 실습을 하고 있던 희원이는 문득 이 문제가 너무 쉽다고 생각했다. 희원이는 실습 도중 반대로 Fn이 주어졌을 때 n을 출력하는 문제는 어떨지 궁금했다.  피보나치 수 Fn이 주어졌을 때 n을 출력하는 프로그램을 만들어 보자.

입력
첫 번째 줄에 테스트케이스를 나타내는 T(1 ≤ T ≤ 100)가 입력으로 주어진다. 두 번째 줄부터 각 테스트케이스마다 양의 정수 Fn이 입력으로 주어진다. (1 ≤ Fn ≤ 1021000, 1 ≤ N ≤ 100,000)

출력
피보나치 수 Fn이 주어졌을 때 n을 출력한다. 만약 가능한 경우가 여러 개 있는 경우에는 가장 큰 인덱스를 출력하라. 피보나치 수가 아닌 수가 들어오는 경우는 없다.

4
1
5
8
1597

10의 21000승..........?......
덧셈이니까 .. string의 num 계산을 하면 될 듯..?

1 1 2 3 5 8 13 21 33 54 87 141 228
*/