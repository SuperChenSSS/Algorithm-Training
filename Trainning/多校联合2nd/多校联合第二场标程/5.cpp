#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#define eps 0.0000000001
#define maxn 3009
#define inf 0x3f3f3f3f
#define mod 1000000009
#define ll long long
using namespace std;
int n,m,f[maxn][maxn],ans=0,a[maxn],ma[maxn][maxn],mi[maxn][maxn],la[maxn];
int yy;
int main()
{
    //freopen("d:\\in.txt","r",stdin);
    scanf("%d",&yy);
    for(int ij=1; ij<=8; ij++)
    {
        memset(f,0,sizeof(f));
        ans=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        //n^2的预处理
        for(int i=1; i<=n; i++)
        {
            mi[i][i]=a[i];
            ma[i][i]=a[i];
            la[i]=i;
            f[i][i]=1;
            for(int j=i+1; j<=n; j++)
            {
                mi[i][j]=min(mi[i][j-1],a[j]);
                ma[i][j]=max(ma[i][j-1],a[j]);
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=n-i+1; j++)
            {
                int k=j+i-1;
                if(ma[j][k]-mi[j][k]!=k-j)
                    f[j][k]=0;
                else
                {
                    if(mi[j][k]<mi[j][la[j]])
                        f[j][k]=1;
                    else
                        f[j][k]=f[j][la[j]]+f[la[j]+1][k];
                    la[j]=k;
                }
            }
        }
        //for(int i=1;i<=n;i++)
        //   for(int j=i;j<=n;j++)
        //       printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        //n^2的区间暴力
        for (int i=1; i<=n; i++)
        {
            for (int j=i; j<=n; j++)
            {
                if (f[i][j]&&((i==1||(f[1][i-1]&&mi[1][i-1]==1)))) //判断第一段要交换的区间和最后留下的区间是否相连
                {
                    int jj=ma[i][j];
                    if (jj==n||(ma[jj+1][n]==n&&f[jj+1][n]))
                        for (int ii=jj; ii>j; ii--)
                            if (f[ii][jj]&&mi[ii][jj]==i)
                                ans=max(ans,f[1][i-1]+f[j+1][ii-1]+f[jj+1][n]+2);
                }
            }
        }
        ans=max(ans,f[1][n]);
        printf("%d\n",ans);
    }
    return 0;
}