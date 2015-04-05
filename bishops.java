import java.util.Scanner;
import java.math.BigInteger;
class Solution{
	public static void main(String []args){
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNextLine()){
			String num=scanner.nextLine();
			BigInteger bnum=new BigInteger(num);
			if(bnum.compareTo(new BigInteger(Integer.toString(1)))!=0){
				bnum=bnum.add(bnum);
				bnum=bnum.subtract(new BigInteger(Integer.toString(2)));
				System.out.println(bnum);
			}
			else{
				System.out.println("1");
			}
		}
	}
}
