import java.math.BigInteger;
import java.util.Scanner;
class Solution{
    public static void main(String []args){
        Scanner in = new Scanner(System.in);
        int t;
        t=in.nextInt();
        while(t!=0){
            int n;
            BigInteger fact=new BigInteger(new String("1"));
            n=in.nextInt();
            while(n>1){
                fact=fact.multiply(new BigInteger(String.valueOf(n)));
                n--;
            }
            System.out.println(fact);
            t--;
        }
        
    }
}