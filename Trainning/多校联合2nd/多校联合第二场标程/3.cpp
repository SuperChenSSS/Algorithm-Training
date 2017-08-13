#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
struct Node{int p, v;};
deque<Node> que;
int n,a[250025],x,h[250025],ans;
vector<int> b;

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
//    auto start = clock();
    while(cin >> n){
        ans = 0;
        que.clear(); b.clear();
        memset(h,0,sizeof h);
        for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
        for(int i = 1;i <= n;++i){
            scanf("%d",&x);
            h[x]++;
        }
        for(int i = 1;i <= n;++i)
            for(int j = 0;j < h[i];++j)
                b.push_back(i);
        for(int i = 1;i <= n;++i){
            while(!que.empty() && que.back().v <= a[i] - i) que.pop_back();
            que.push_back({i,a[i] - i});
        }
        for(int i = 1;i <= n;++i){
            while(que.front().p < b[i-1]) que.pop_front();
            int t = que.front().v;
            ans = (ans + t) % MOD;
            t = max(t-i-n,0);
            while(que.back().v <= t) que.pop_back();
            que.push_back({i+n,t});
        }
        cout << ans << endl;
    }
//    cout << (clock() - start) / (double)CLOCKS_PER_SEC;

    return 0;
}
