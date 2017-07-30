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
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;

int main()
{
	//freopen("d.in","r",stdin);
	int t,l,r;
	long long n;
	int arra[maxn],arrb[maxn];
	cin>>t;
	int cas = 1;
	while(t--)
	{
		for(int i=1;i<=52;i++)
			cin>>arra[i];
		cin>>n>>l>>r;
		int step = n % r;
		while(step--)
		{
			int pos = 1;
			for(int i=l;i<=r;i++)
				arrb[pos++] = arra[i];
			for(int i=1;i<=l-1;i++)
				arrb[pos++] = arra[i];
			for(int i=r+1;i<=52;i++)
				arrb[pos++] = arra[i];
			for(int i=1;i<=52;i++)
				arra[i] = arrb[i];
		}
		printf("Case #%d:",cas);
		cas++;
		for(int i=1;i<=52;i++)
			cout<<" "<<arra[i];
		cout<<"\n";
	}	
	return 0;
}