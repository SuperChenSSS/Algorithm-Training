#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int T,n,m,p;
int main()
{
	//freopen("test9.in","r",stdin);
	//freopen("test9.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&p);
        int tot=n*m-1;
        int ans=0;
        while(tot>p)
        {
            int t=(tot-1)/p+1;
            ans+=(t-1)*(p-1)*t/2;
            tot-=t;
        }
        printf("%s\n",((ans%2)?"NO":"YES"));
    }
    return 0;
}
