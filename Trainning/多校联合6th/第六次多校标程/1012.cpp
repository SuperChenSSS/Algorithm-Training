#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------
const int N = 1e5 + 7;
const int M = 17;
int n, q, W, pw, dw, a[N], H[N], lx[N], rx[N];
int st[N][M], st2[N][M];
void get_next(int W, int nx[]) {
    for (int i = 0, j = 0, w = -1; i <= n; ++i) {
        while (w + a[j] + 1 <= W) w += a[j++] + 1;
        nx[i] = j, w -= a[i] + 1;
    }
}
char in[] = { "../typesetting data/data.in" };
char out[] = { "data.out" };
int main() {
    //freopen(in, "r", stdin);
    //freopen(out, "w", stdout);
    int T;
    scanf("%d", &T);
    rep(cas, 0, T) {
        scanf("%d%d%d%d", &n, &W, &pw, &dw);
        assert(1 <= n && n <= 100000);
        assert(pw + dw <= W);
        rep(i, 0, n) scanf("%d", a + i);
        rep(i, 0, n) assert(1 <= a[i] && a[i] <= W);
        H[n] = 0, a[n] = W + 7;
        get_next(W, lx);
        for (int i = n - 1; i >= 0; --i)
            H[i] = H[lx[i]] + 1;
        rep(i, 0, n + 1) st[i][0] = lx[i];
        rep(j, 1, M)
            for (int i = 0; i <= n; ++i)
                st[i][j] = st[st[i][j - 1]][j - 1];
        get_next(dw, lx), get_next(W - pw - dw, rx);
        rep(i, 0, n + 1) st2[i][0] = rx[lx[i]];
        rep(j, 1, M)
            for (int i = 0; i <= n; ++i)
                st2[i][j] = st2[st2[i][j - 1]][j - 1];
        scanf("%d", &q);
        rep(_q, 0, q) {
            int x, h, id = 0, row = 0;
            scanf("%d%d", &x, &h);
            row += min(--x, H[0]);
            rep(i, 0, M)
                if (x >> i & 1)
                    id = st[id][i];
            rep(i, 0, M)
                if (h >> i & 1)
                    id = st2[id][i];
            row += h + H[id];
            printf("%d\n", row);
        }
    }
    return 0;
}
