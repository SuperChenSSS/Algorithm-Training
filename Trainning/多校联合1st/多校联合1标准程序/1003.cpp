#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , ca;
vector<int> e[N] , c[N];
int L[N] , R[N] , s[N] , f[N];

void dfs(int x , int fa , int &&ncnt) {
    L[x] = ++ ncnt;
    s[x] = 1 , f[x] = fa;
    for (auto &y : e[x]) {
        if (y != fa) {
            dfs(y , x , move(ncnt));
            s[x] += s[y];
        }
    }
    R[x] = ncnt;
}
bool cmp(const int& x , const int& y) {
    return L[x] < L[y];
}
void work() {
    for (int i = 0 ; i <= n ; ++ i) {
        c[i].clear();
        e[i].clear();
    }
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d" , &x);
        c[x].push_back(i);
    }
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    e[0].push_back(1);
    dfs(0 , 0 , 0);
    LL res = (LL)n * n * (n - 1) / 2;
    for (int i = 1 ; i <= n ; ++ i) {
        if (c[i].empty()) {
            res -= (LL)n * (n - 1) / 2;
            continue;
        }
        c[i].push_back(0);
        sort(c[i].begin() , c[i].end() , cmp);
        for (auto &x : c[i]) {
            for (auto &y : e[x]) {
                if (y == f[x])
                    continue;
                int size = s[y];
                int k = L[y];
                while (1) {
                    L[n + 1] = k;
                    auto it = lower_bound(c[i].begin() , c[i].end() , n + 1 , cmp);
                    if (it == c[i].end() || L[*it] > R[y]) {
                        break;
                    }
                    size -= s[*it];
                    k = R[*it] + 1;
                }
                //printf("%d] %d %d : %d\n" , i , x , y , size);
                res -= (LL)size * (size - 1) / 2;
            }
        }

    }
    printf("Case #%d: %lld\n" , ++ ca , res);
}

int main() {
    while (~scanf("%d" , &n)) {
        work();
    }
    return 0;
}
