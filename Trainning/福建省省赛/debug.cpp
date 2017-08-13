#include <stdio.h>
#include <iostream>
using namespace std ;

int main()
{
	int T ;
	int C[2010] = {0} ;
	cin >> T ;
	int t = 1 ;
	int n , m ;
	while(T --)
	{
		int num = 0 ;
		int money = 0 ;
		cin >> n >> m ;
		for(int i = 0 ; i < n ; i ++)
		{
			cin >> C[i] ;
		}
		for(int i = 0 ; i < n ; i ++)
		{
			if(i == n - 1)
			{
				int index = num * C[i] + money ;
				if(m < index)
				{
					m = index ;
				}
				num = 0 ;
			}
			if (C[i] < C[i+1])
			{
				num = m / C[i] ;
				money = m % C[i] ;
				m = num * C[i+1] + money ;
				m = m % 1000000007 ;
				num = 0 ;
			}
		}
		printf("Case #%d: %d\n", t , m % 1000000007);
		t ++ ;
	}
	return 0 ;
}