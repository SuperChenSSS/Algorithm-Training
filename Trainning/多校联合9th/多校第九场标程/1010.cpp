#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool f[2502][2502],ff[2502][2502];
int l[2501];
string sh,ch;
int main()
{
    int t;
    int n,m,i,j;
     
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(ff,0,sizeof(ff));
        cin>>sh>>ch;n=sh.length();m=ch.length();
        sh=' '+sh;ch=' '+ch;f[0][0]=1;ff[0][0]=1;
        for(i=1;i<=n;i++)
            if(sh[i]!=sh[i-1]) l[i]=i;
            else l[i]=l[i-1];
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
            {
                if(i==0&&j==0) continue;
                if(ch[j]=='.'&&i!=0||ch[j]==sh[i]) f[i][j]|=f[i-1][j-1];
                if(ch[j]=='*')
                {
                    f[i][j]|=f[i][j-2];
                    if(ch[j-1]=='.'||ch[j-1]==sh[i])
                        if(sh[i-1]==sh[i]) {f[i][j]|=ff[i-1][j-2];f[i][j]|=f[l[i]-1][j-2];}
                        else f[i][j]|=f[i-1][j-2];
                }
                ff[i][j]=f[i][j];
                if(sh[i]==sh[i-1]) ff[i][j]|=ff[i-1][j];
            }
        if(f[n][m]==1) cout<<"yes\n";
        else cout<<"no\n";
    }
}