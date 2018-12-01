/// PROB ->http://codeforces.com/problemset/problem/869/B

import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        long a = sc.nextLong();
        long b = sc.nextLong();

        long c = b - a;

        BigInteger sum = new BigInteger("1");

        for(int i=0;i<c;i++){

            sum = sum.multiply(BigInteger.valueOf(b-i));

            if(sum.mod(BigInteger.valueOf(10)).compareTo(BigInteger.valueOf(0))==0)break;
        }
        System.out.println(sum.mod(BigInteger.valueOf(10)));
    }
}
