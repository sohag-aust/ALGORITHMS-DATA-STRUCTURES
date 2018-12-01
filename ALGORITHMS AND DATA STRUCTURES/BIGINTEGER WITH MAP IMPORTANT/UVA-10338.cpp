
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();

        for (int i = 1; i <= test; i++) {

            String str = sc.next();
            Map<Character, Integer> mp = new HashMap<>();

            BigInteger mul1 = BigInteger.ONE;
            BigInteger mul2 = BigInteger.ONE;

            for (int j = 0; j < str.length(); j++) {

                mul1 = mul1.multiply(BigInteger.valueOf(j + 1));
                char ch = str.charAt(j);
                Integer val = mp.get(ch);

                if (val == null) {
                    mp.put(ch, 1);
                } else {
                    mp.put(ch, val + 1);
                }
            }

            for (Map.Entry<Character, Integer> entry : mp.entrySet()) /// we make entryset for iterating map
            {
                mul2 = BigInteger.ONE;
                char ch = entry.getKey();
                Integer val = entry.getValue();

                for (int k = 1; k <= val; k++) {
                    mul2 = mul2.multiply(BigInteger.valueOf(k));
                }

                mul1 = mul1.divide(mul2);
            }

            System.out.println("Data set " + i + ": " + mul1);
        }
    }
}
