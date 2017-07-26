#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    const int maxn = 1e6;
    int l,n,t;
    int x[maxn];
    cin>>t;
    while(t--){
        cin>>l>>n;
        for(int i=0;i<n;i++)
            cin>>x[i];
        int minT = 0;
        for(int i=0;i<n;i++)
            minT = max(minT,min(x[i],l-x[i]));
        int maxT = 0;
        for(int j=0;j<n;j++)
            maxT = max(maxT,max(x[j],l-x[j]));
        cout<<minT<<" "<<maxT<<endl;
    }
    return 0;
}