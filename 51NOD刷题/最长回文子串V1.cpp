#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
int f[maxn];
char str[maxn];
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>str)
	{
		int id = 0,maxlen = 0;
		memset(f,0,sizeof(f));
		int len = strlen(str);
		//扩充为原来两倍长，中间补*号
		for(int i=len;i>=0;i--)
		{
			str[2*i+2] = str[i];
			str[2*i+1] = '*';
		}
		str[0] = '#';
		for(int i=2;i<2*len+1;i++)
		{
			if(f[id]+id>i)
				f[i] = min(f[2*id-i],f[id]+id-i);
			else
				f[i] = 1;
			while(str[i-f[i]]==str[i+f[i]])
				f[i]++;
			if(id+f[id]<i+f[i])
				id = i;
			maxlen = max(maxlen,f[i]);
		}
		cout<<maxlen-1<<endl;
	}
	return 0;
}