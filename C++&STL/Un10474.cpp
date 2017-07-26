//lower_bound()函数：查找大于或等于x的第一个位置
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 1e4;

int main()
{
    int n,q,x,a[maxn],kase = 0;
    while(cin>>n>>q && n){
        cout<<"CASE# "<<++kase<<":"<<endl;
        for(int i=0;i<n;i++)    cin>>a[i];
        sort(a,a+n);//STL库中排序函数
        while(q--){
            cin>>x;
            int p = lower_bound(a,a+n,x) - a;//在已排序数组中寻找x
            if(a[p]==x)     cout<<x<<" found at "<<p+1<<endl;
            else cout<<x<<" not found"<<endl;
        }
    }
    return 0; 
}