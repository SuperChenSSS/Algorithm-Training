#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int r,n,arr[1000];
    while(cin>>r>>n&&(r!=-1 && n!=-1))
    {
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int i = 0,ans = 0;
        while(i<n)
        {
            //s是没有被覆盖的最左的点的位置
            int s = arr[i++];
            //一直向右前进直到距离s的距离大于R的点
            while(i<n && arr[i]<=s + r)
                i++;

            //p是新加上标记的点的位置
            int p = arr[i-1];
            //一直向右前进直到距p的距离大于r的点
            while(i<n && arr[i]<=p+r)
                i++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
