#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std ;
typedef long long ll;
const int maxn = 1e6 ;
ll hang[maxn],lie[maxn];
int main()
{
	ios::sync_with_stdio(false);
	freopen("adjustment.in","r",stdin);
	freopen("adjustment.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	hang[0] = lie[0] = (n*n+n)/2;
	for(int i=1;i<=n;i++)
	{
		hang[i] = hang[i-1] + n;
		lie[i] = hang[i];
		//cout<<hang[i]<<" "<<lie[i]<<endl;
	}
	ll hea = 0,heb = 0,timea = 0,timeb = 0;
	while(q--)
	{
		char f;ll val;cin>>f>>val;
		switch(f)
		{
			case 'R':
				if(hang[val]==0)    {cout<<0<<endl;break;}
				cout<<hang[val]-(timea*val+hea)<<endl;
				//printf("%d\n",hang[val]-(timea*val+hea));
				hang[val] = 0;
				timeb++;heb += val;
				break;
			case 'C':
				if(lie[val]==0)    {cout<<0<<endl;break;}
				cout<<lie[val]-(timeb*val+heb)<<endl;
				//printf("%d\n",lie[val]-(timeb*val+heb));
				lie[val] = 0;
				timea++;hea += val;
				break;
			default:
				break;
		}
		/*for(int i=1;i<=n;i++)
			cout<<hang[i]<<" "<<lie[i]<<endl;*/
	}
	return 0 ;
}