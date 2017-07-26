#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return (a>b);}
int main()
{
    ios::sync_with_stdio(false);
    const int N = 1e6;
    int t , n,m;
    int a[N],b[N];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<m;i++)
            cin >> b[i];
        sort(a , a+n,cmp) ;
        sort(b , b+m) ;
        long sum = 0;
        int i = n -1, j = 0;
        while(i>=0&&j<=m-1&&a[i]>=b[j])
                sum += (a[i--] - b[j++]);
        cout<<sum<<endl;
    }
    return 0;
}