#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,i,T,k1,k2;
    int l[5],r[5],ll,rr;
    char s1[80010],s2[80010];
    cin>>T;
    while(T--)
    {
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s",s1);
        scanf("%s",s2);
        k1=k2=0;
        for(i=0;i<n;i++)
            if (s1[i]==s2[i]) k1++;
            else k2++;
        l[1]=0;r[1]=k2;
        l[2]=x-y;r[2]=k2+x-y;
        if (x-y>=0) l[3]=(x-y+1)/2; else l[3]=(x-y)/2;
        if (k2+x-y>=0) r[3]=(k2+x-y)/2; else r[3]=(k2+x-y-1)/2;
        l[4]=x-k1;r[4]=x;
        ll=max(max(l[1],l[2]),max(l[3],l[4]));
        rr=min(min(r[1],r[2]),min(r[3],r[4]));
        if (ll<=rr) printf("Not lying\n");
        else printf("Lying\n");
    }
    return 0;
}
