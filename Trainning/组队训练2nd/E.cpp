//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue>
using namespace std;
#define ll  long long  
ll as[]={0,1,2,6,24,120,720,5040,  40320,  362880 , 3628800 , 39916800,  479001600 , 6227020800 , 87178291200,  
	1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000,  121645100408832000 , 2432902008176640000  
},xx[8]={2,3,5,7,11,13,17,19};  
int flag = 0;  
void dfs(ll x,ll q)  
{  
	if(flag)	
		return;  
	if(x==1)
	{  
		flag = 1;  
		return;  
	}  
	if(flag==1)	
		return;  
	for(int i=q;i>=2;i--)  
	{  
		if(x%as[i]==0)
		{
			dfs(x/as[i],i);  
			if(!flag)
			{  
				for(int j=0;j<8;j++)  
				{  
					if(xx[j]==i)
						return;  
					if(xx[j]>i)
						break;  
				}  
			}	  
		}  
		if(flag)	
			return;  
	}  
}
int main()  
{ 
	ll n,a,i,j,k;  
	cin>>n;  
	while(n--)  
	{  
		cin>>a; 
		if(a==1)
		{  
			cout<<"YES\n"; 
			continue;  
		}  
		flag=0;  
		dfs(a,20);  
		if(flag)	cout<<"YES\n";  
		else 	cout<<"NO\n";  
	}
	return 0;  
}  