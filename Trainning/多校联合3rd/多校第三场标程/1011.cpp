#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
    int t;scanf("%d",&t);
    int ans=0;
    while(t--){
        int x;scanf("%d",&x);
        if(x<=35)++ans;
    }
    printf("%d\n",ans);
    return 0;
}