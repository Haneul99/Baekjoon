import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args)  {
    	Scanner input=new Scanner(System.in);
    	int n=input.nextInt();
    	int m=input.nextInt();
    	input.nextLine();
    	HashSet<String> listen=new HashSet<String>();
    	
    	for(int i=0;i<n;i++) {
    		String person=input.nextLine();
    		listen.add(person);
    	}
    	
    	String noListen_noSee[]=new String[500000];
    	int idx=0;
    	for(int i=0;i<m;i++) {
    		String person=input.nextLine();
    		if(listen.contains(person)) {
    			noListen_noSee[idx]=person;
    			idx++;
    		}
    	}
    	Arrays.sort(noListen_noSee,0,idx);
    	System.out.printf("%d\n",idx);
    	for(int i=0;i<idx;i++)
    		System.out.printf("%s\n",noListen_noSee[i]);
    }
}


/*
1764. 듣보잡 
https://www.acmicpc.net/problem/1764

문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

출력
듣보잡의 수와 그 명단을 사전순으로 출력한다.

*/