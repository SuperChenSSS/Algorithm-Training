#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int vis[10005];
vector<PII> sum[10005];
LL n, m, l, a[105], b[105], c[105][105], w[105][105];
void read(LL &o) {
    o = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        o = o * 10 + c - '0';
        c = getchar();
    }
}
LL work(int value) {
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL tmp, tot = 0, sum = 0;
        for (int j = 1; j <= m; ++j) {
            if (w[i][j] != value)
                c[i][j] = c[i - 1][j] + 1;
            else
                c[i][j] = 0;
            tmp = 1;
            while (tot && a[tot] >= c[i][j]) {
                tmp += b[tot];
                sum -= a[tot] * b[tot];
                tot--;
            }
            tot++;
            a[tot] = c[i][j];
            b[tot] = tmp;
            sum += a[tot] * b[tot];
            ans += sum;
        }
    }
    return ans;
}

LL work2(int value) {
    auto siz = sum[value].size();
    LL tot = 0;
    for (int i = 1; i < (1 << siz); ++i) {
        bool flag = 0;
        LL uu = n + 500, dd = -1, ll = n + 500, rr = -1;
        for (int j = 0; j < siz; ++j) {
            if (i >> j & 1) {
                flag = !flag;
                uu = min(1LL * sum[value][j].first, uu);
                dd = max(1LL * sum[value][j].first, dd);
                ll = min(1LL * sum[value][j].second, ll);
                rr = max(1LL * sum[value][j].second, rr);
            }
        }
        if (flag) {
            tot += uu * (n - dd + 1) * ll * (n - rr + 1);
        } else {
            tot -= uu * (n - dd + 1) * ll * (n - rr + 1);
        }
    label:
        continue;
    }
    return tot;
}
int main() {
    freopen("/Users/mac/Desktop/出题/data.in", "r",stdin);
    freopen("/Users/mac/Desktop/出题/data.out", "w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        read(n);
        read(m);
        l = 0;
        for(int i = 0;i < n * m; ++i){
                sum[i].clear();
        }
        memset(vis,0,sizeof(vis));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                read(w[i][j]);
                if (vis[w[i][j]])
                    continue;
                vis[w[i][j]] = ++l;
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                w[i][j] = vis[w[i][j]];
                sum[w[i][j]].push_back(PII(i, j));
            }
        double ans = 0;
        LL lx = n * (n + 1) * m * (m + 1) / 4;
        for (int i = 1; i <= l; ++i) {
            if (sum[i].size() > 13) {
                LL tmp = work(i);
                ans += (lx - tmp) / (1.0 * lx);
            } else {
                ans += work2(i) / (1.0 * lx);
            }
        }
        printf("%.9f\n", ans);
    }
    return 0;
}
