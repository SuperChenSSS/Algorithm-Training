/*深度优先搜索从最开始的状态出发，遍历所有可以到达的状态。
由此可以对所有的状态进行操作，或者列举出所有的状态*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e6;
int a[maxn],n,k;
bool dfs(int i,int sum){
        //已经从第i项得到了和sum,然后对于i项之后的进行分支
        if(sum>k||sum+a[i]>k) return false;
        if(i == n)  return sum == k;//如果前n项都计算过了，则返回sum是否与k相等
        if(dfs(i+1,sum))    return true;//不加上a[i]的情况
        if(dfs(i+1,sum+a[i]))   return true;//加上a[i]的情况
        //无论是否加上a[i]都不能凑成k就返回false
        return false;
    }
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(dfs(0,0))    cout<<"Yes\n";
    else    cout<<"No\n";
    return 0;
}