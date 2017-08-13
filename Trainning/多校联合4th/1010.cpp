//TDteam01
/*STL
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
queue<int>a,b;
int main()
{
	ios::sync_with_stdio(false);
	int t,tmp;
	cin>>t;
	while(t--)
	{
		int n,k,time = 0;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			a.push(tmp);
		}
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			b.push(tmp);
		}
		while(!a.empty() || !b.empty())
		{
			if(abs(a.front()-b.front())>k && !a.empty() && !b.empty())
			{
				a.pop();
				b.pop();
				time++;
			}
			else if(a.front()>=b.front() && !a.empty())
			{
				a.pop();
				time++;
			}
			else if(a.front()<=b.front() && !b.empty())
			{
				b.pop();
				time++;
			}
		}
		cout<<time<<"\n";
	}
	return 0;
}*/
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

int a,b;

int q1[60010],q2[60010];

int main()
{
	ios::sync_with_stdio(false);
	int t,tmp;
	cin>>t;
	while(t--)
	{
		int n,k,time = 0;
		a = 0;
		b = 0;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
		    scanf("%d",&q1[i]);
		}
		for(int i=0;i<n;i++)
		{
		    scanf("%d",&q2[i]);
		}
		while(a<=n-1 || b<=n-1)
		{
			if(abs(q1[a]-q2[b])>k && a<=n-1 && b<=n-1)
			{
				++a;
				++b;
				time++;
			}
			else if(q1[a]>=q2[b] &&  a<=n-1)
			{
			    ++a;
				time++;
			}
			else if(q1[a]<=q2[b] && b<=n-1)
			{
				++b;
				time++;
			}
		}
		cout<<time<<"\n";
	}
	return 0;
}