#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e8;
int n,s[maxn],t[maxn];//输入
pair<int,int>  itv[maxn];//用于对工作排序的pair数组
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    //对pair进行的是字典序比较
    //为了让结束时间早的工作排在前面，把T存入first，把S存入second
    for(int i=0;i<n;i++){
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv,itv+n);
    //t是最后所选工作的结束时间
    int ans = 0,T = 0;
    for(int i=0;i<n;i++)
        if(T<itv[i].second){
            ans++;
            T = itv[i].first;
        }
    cout<<ans<<endl;
    return 0;
}