#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    const int v[6] = {1,5,10,50,100,500};
    int C[6],sum,ans;
    cin>>sum;
    for(int i=0;i<6;i++)
        cin>>C[i];
    for(int i=5;i>=0;i--){
        int t = min(sum/v[i],C[i]);//使用硬币i的枚数
        sum -= t * v[i];
        ans += t;
    }
    cout<<ans<<endl;
    return 0;
}