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
char ma[2*maxn];
int mp[2*maxn];
void Manacher(char s[],int len)
{
	int l = 0;
	ma[l++] = '$';
	ma[l++] = '#';
	for(int i=0;i<len;i++)
	{
		ma[l++] = s[i];
		ma[l++] = '#';
	}
	ma[l] = 0;
	int mx = 0,id = 0;
	for(int i=0;i<l;i++)
	{
		mp[i] = mx>i?min(mp[2*id-i],mx-i):1;
		while(ma[i+mp[i]]==ma[i-mp[i]])
			mp[i]++;
		if(i+mp[i]>mx)
		{
			mx = i + mp[i];
			id = i;
		}
	}
}
char arr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>arr)
	{
		memset(ma,0,sizeof(ma));
		memset(mp,0,sizeof(mp));
		int len = strlen(arr);
		Manacher(arr, len);
		int ans = 0;
		for(int i=0;i<2*len+2;i++)
			ans = max(ans,mp[i]-1);
		cout<<ans<<endl;
	}
	return 0;
}