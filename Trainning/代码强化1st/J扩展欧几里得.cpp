#include <iostream>
#include <stdio.h>
using namespace std ;
/*扩展欧几里得算法：
	求(ax+by=gcd的解以及逆元素)
	思路：
	设(A/B)%9973 = K, 则A/B = k + 9973x  (x未知）， 因此A = kB + 9973xB,
	又A%9973 = n， 所以kB%9973 = n,  故kB = n + 9973y (y未知)
	故(k/n)B +(-y/n)*9973 = gcd(B,9973) = 1
	扩展欧几里得 求出k/n,  再乘以个n，记得取模，就是answer了
*/
int extendgcd(int a,int b, long long &x, long long &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return 0;
	}
	int m = extendgcd(b,a%b,x,y);
	long long t = x;
	x = y;
	y = t - a/b * y;
	return m;
}

int main()
{
	int  B, i = 0,t;
	long long n, result;
	cin>>t;
	while(t--)
	{
		cin >> n >> B ;
		long long x,y;
		extendgcd(B,9973,x,y);
		result = x*n % 9973;
		result = (result + 9973)%9973;
		cout << result<< "\n" ;
	}

}