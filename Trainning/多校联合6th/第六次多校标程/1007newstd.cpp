#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define lowbit(x) (x&(-x))
#define fi first
#define se second

const int N = 100005;

int T, n, p[N], m, v[N];
vector<pii> q[N];
ll bit[N];

void add(int x, ll w) {
    while (x <= n) {
        bit[x] += w;
        x += lowbit(x);
    }
}

void add(int l, int r, ll w) {
    add(l, w); add(r + 1, -w);
}

ll get(int x) {
    ll ans = 0;
    while (x) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

int tmp[N], tn;
vi pri[N];
vector<pii> fac[N];
ll ans[N], cnt[N];

ll gt(int x) {
    ll ans = 0;
    for (int i = 0; i < sz(fac[x]); i++)
        ans += cnt[fac[x][i].fi] * fac[x][i].se;
    return ans;
}

ll ad(int x, ll w) {
    for (int i = 0; i < sz(fac[x]); i++)
        cnt[fac[x][i].fi] += w;
}

int main() {
    for (int i = 2; i < N; i++) {
        if (tmp[i]) continue;
        for (int j = i; j < N; j += i) {
            pri[j].pb(i);
            tmp[j] = 1;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < (1<<sz(pri[i])); j++) {
            fac[i].pb(mp(1, 1));
            for (int k = 0; k < sz(pri[i]); k++) {
                if (j>>k&1) {
                    fac[i][j].fi *= pri[i][k];
                    fac[i][j].se *= -1;
                }
            }
        }
    }
    //freopen("./data/in_small", "r", stdin);
    //freopen("./data/out_small", "w", stdout);
    //freopen("./data/in_small", "r", stdin);
    //freopen("out1", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]), q[i].clear(), v[p[i]] = i, bit[i] = 0;
        for (int i = 1; i <= m; i++) {
            int l, r; scanf("%d%d", &l, &r);
            q[r].pb(mp(l, i));
        }
        for (int i = 1; i <= n; i++) {
            tn = 0;
            for (int j = 2 * p[i]; j <= n; j += p[i])
                if (v[j] < i) tmp[++tn] = v[j];
            sort(tmp + 1, tmp + tn + 1);
            ll sum = 0;
            for (int j = tn; j >= 1; j--) {
                sum += gt(p[tmp[j]] / p[i]) * p[i];
                add(tmp[j - 1] + 1, tmp[j], sum);
                ad(p[tmp[j]] / p[i], 1);
            }
            for (int j = tn; j >= 1; j--)
                ad(p[tmp[j]] / p[i], -1);
            for (int j = 0; j < sz(q[i]); j++)
                ans[q[i][j].se] = get(q[i][j].fi);
        }
        for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    }
    return 0;
}

/*
1
6 1
6 5 4 3 2 1
1 6
*/
