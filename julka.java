import java.math.BigInteger;
import java.util.Scanner;
class Solution{
    public static void main(String []args){
        Scanner in = new Scanner(System.in);
        String num;
        int nt=10;
        BigInteger ans;
        while(nt>0){
            num=in.nextLine();
            BigInteger t=new BigInteger(num);
            num=in.nextLine();
            BigInteger m=new BigInteger(num);
            ans=t.subtract(m);
            ans=ans.divide(new BigInteger(Integer.toString(2)));
            System.out.println(ans.add(m));
            System.out.println(ans);
            nt--;
        }
    }
}