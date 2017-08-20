#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue> 
using  namespace std;
typedef long long ll;
const double eps=1e-6;
const double PI=acos(-1.0);
const int INF=1e6;
const int mod=1e9+7;
const int maxn=1e3+10;
ll arr[maxn];
char s[maxn];

int main()
{
	arr[0]=1;
	for(int i=1; i<maxn; i++) 
		arr[i] = arr[i-1] * 10;
	int t;
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		cin>>s;
		int len=strlen(s);
		ll ans=0;
		for(int i=0; i<len; i++)
		{
			if(isdigit(s[i])) 
				ans = ans * 10 + s[i] - '0';
			else
			{
				if(s[i]=='(')
				{
					ll tmp=0,wei=0,num=0;
					i++;
					while(i<len&&s[i]!=')')
					{
						tmp=tmp*10+(s[i]-'0');
						i++;
						wei++;
					}
					i += 3;
					while(i<len && s[i]!=')')
					{
						num = num*10+(s[i]-'0');
						i++;
					}
					for(int j=0; j<num; j++)
						ans = (ans * arr[wei] + tmp) % mod;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}