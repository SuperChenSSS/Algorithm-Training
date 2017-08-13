//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long LL;

int mul(int a,int b){
    LL c = 1LL * a * b;
    return c - c / MAX * MAX;
}

void add(int &a,int b){
    a += b;
    if(a >= MAX) a -= MAX;
}

int phi(int k)
{
    int i,s;
    s = k;
    for(i = 2;i * i <= k; i++)
    {
        if(k % i == 0) s = s / i * (i - 1);
        while(k % i == 0) k /= i;
    }
    if(k > 1) s = s / k * (k - 1);
    return s;
}

int solve(int n){
    int i,j,ans = 0;
    for(i = 1;i * i <= n; i++){
        j = n / i;
        if(i * j == n){
            add(ans,mul((1LL * j * phi(j) + (j == 1)) / 2 % MAX,mul(i,i)));
            if(i != j) add(ans,mul((1LL * i * phi(i) + (i == 1)) / 2 % MAX,mul(j,j)));
        }
    }
    ans -= mul(mul(n,n + 1),500000004);
    if(ans < 0) ans += MAX;
    return ans;
}

bool isprime(int x){
    for(int i = 2;i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int t,m,p,cas;
    scanf("%d",&t);
    for(cas = 1;cas <= t; cas++){
        scanf("%d%d",&m,&p);
        assert(1 <= m && m < p && p >= 2 && p <= MAX && isprime(p));
        printf("Case #%d: %d\n",cas,mul(solve(p - 1),m));
    }
    return 0;
}
