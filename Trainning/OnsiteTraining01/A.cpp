#include<iostream>
#include<cmath>
#include<cstring>
#include<ctype.h>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	//freopen("2.txt","r",stdin);
	ll a,b,c;
	while(cin>>c>>a>>b&&c)
	{
		c /= 2;
		ll ans = c / fabs(a-b) * a;
		//cout<<ans<<endl;
		if(ans>0)//zhengshu
		{
			if(c%(ll)fabs(a-b)==0)
			{
				cout<<ans<<endl;
			}
			else if(ans>c)
			{
				cout<<a*c%(ll)(fabs(a-b)*c)<<"/"<<fabs(a-b)<<endl;
			}
			else//xiaoshu
			{
				cout<<a*c<<"/"<<fabs(a-b)<<endl;
			}
		}
		else
		{
			ans *= -1;
			if(c%(ll)fabs(a-b)==0)
				cout<<-ans+c*2<<endl;
			else if(ans>c)
			{
				cout<<-a*c%(ll)(fabs(a-b)*c)+fabs(a-b)*c<<"/"<<fabs(a-b)<<endl;
			}
			else//xiaoshu
			{
				cout<<-a*c<<"/"<<fabs(a-b)<<endl;
			}
		}
	}
	return 0;
}