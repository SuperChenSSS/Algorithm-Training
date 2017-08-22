#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <map>

using namespace std;

vector<int>ab,a;
map<int,int>p;

int main(){
    //freopen("in.txt","r",stdin);
    int m;
    while(~scanf("%d",&m)){
        ab.clear();
        a.clear();
        p.clear();
        int x;
        for(int i=0;i<m;i++){
            scanf("%d",&x);
            p[x]++;
            ab.push_back(x);
        }
        sort(ab.begin(),ab.end());
        a.push_back(ab[0]);
        p[ab[0]]--;
        for(int i=1;i<ab.size();i++){
            if( p[ab[i]] == 0 )
                continue;
            for(int j=0;j<a.size();j++)
                p[ab[i]+a[j]]--;
            a.push_back(ab[i]);
            p[ab[i]]--;
        }
        printf("%d\n",a.size());
        for(int i=0;i<a.size();i++)
            printf("%d%c",a[i],i==a.size()-1?'\n':' ');
    }
    return 0;
}
