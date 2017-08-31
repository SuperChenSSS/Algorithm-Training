import java.util.*;
import java.math.*;
public class Jiecheng {
	public static void main(String[] args)
	{
		Scanner cin = new Scanner ( System.in );
		BigInteger n = BigInteger.ZERO,res = BigInteger.ONE;
		n = cin.nextBigInteger();
		for(BigInteger i=BigInteger.ONE;i.compareTo(n)<=0;i=i.add(BigInteger.ONE))
		{
			res = res.multiply(i);
		}
		System.out.println(res);
	}
}
