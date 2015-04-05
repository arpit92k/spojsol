import java.util.Scanner;
import java.math.BigInteger;
class Solution{
	public static void main(String []args){
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t-->0){
			BigInteger a,b;
			a=in.nextBigInteger();
			b=in.nextBigInteger();
			System.out.println(gcd(a,b));
		}
	}
	private static BigInteger gcd(BigInteger a,BigInteger b){
		if (b.compareTo(new BigInteger(new String("0")))==0)
			return a;
		else
			return gcd(b,a.mod(b));
	}
}
