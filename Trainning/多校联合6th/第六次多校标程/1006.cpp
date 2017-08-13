#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef pair<int, int> pii;
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
typedef long long ll;

const int N = 25;
int T, n, m;
char g[105][105], G[105][105];
int sx, sy;
int As, Ds, Hs, Ms;
int A, D, H, M;
int w[4];

int gt[1<<7][4];
int vis[105][105], can[1<<7];
queue<pii> Q;

int getc(char c) {
    if (c == 'A') return 0;
    if (c == 'D') return 1;
    if (c == 'H') return 2;
    return 3;
}

bool bfs(int s) {
    memset(gt[s], 0, sizeof(gt[s]));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] = G[i][j];
            vis[i][j] = 0;
            if (g[i][j] >= '0' && g[i][j] <= '6') {
                int t = g[i][j] - '0';
                if (s>>t&1) g[i][j] = '.';
                else g[i][j] = '#';
            }
        }
    }
    Q.push(mp(sx, sy));
    int ss = 0;
    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        if (g[u.fi][u.se] != '.') {
            int c = getc(g[u.fi][u.se]);
            gt[s][c] += w[c];
        } else if (G[u.fi][u.se] != '.') ss ^= (1<<(G[u.fi][u.se] - '0'));
        for (int i = 0; i < 4; i++) {
            int x = u.fi + dir[i][0];
            int y = u.se + dir[i][1];
            if (x <= 0 || x > n || y <= 0 || y > m || g[x][y] == '#' || vis[x][y]) continue;
            vis[x][y] = 1;
            Q.push(mp(x, y));
        }
    }
    return ss == s;
}

ll dp[1<<7][N][N];
int tmp[4];

int At[7], Hp[7];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", G[i] + 1);
            for (int j = 1; j <= m; j++) {
                if (G[i][j] == 'S') {
                    sx = i; sy = j;
                    G[i][j] = '.';
                }
            }
        }
        for (int i = 0; i < 7; i++) scanf("%d%d", &At[i], &Hp[i]);
        scanf("%d%d%d%d", &As, &Ds, &Hs, &Ms);
        scanf("%d%d%d%d", &A, &D, &H, &M);
        for (int i = 0; i < 4; i++) scanf("%d", &w[i]);
        for (int s = 0; s < (1<<7); s++) can[s] = bfs(s);
        As = min(20, As + gt[0][0]); Ds = min(20, Ds + gt[0][1]); Hs += gt[0][2];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= 20; i++) {
            for (int j = 0; j <= 20; j++) {
                if ((i + j) * M <= Ms + gt[0][3]) {
                    dp[0][min(i * A + As, 20)][min(j * D + Ds, 20)] = max(dp[0][min(i * A + As, 20)][min(j * D + Ds, 20)], Hs + 1ll * (Ms + gt[0][3] - (i + j) * M) / M * H);
                }
            }
        }
        for (int s = 0; s < (1<<7); s++) {
            if (!can[s]) continue;
            for (int i = 1; i <= 20; i++) {
                for (int j = 0; j <= 20; j++) {
                    if (dp[s][i][j] == -1) continue;
                    for (int x = 0; x < 7; x++) {
                        if (s>>x&1) continue;
                        if (!can[s^(1<<x)]) continue;
                        int ti = (Hp[x] + i - 1) / i;
                        int ct = max(0, At[x] - j) * ti;
                        if (dp[s][i][j] - ct <= 0) continue;
                        for (int y = 0; y < 4; y++)
                            tmp[y] = gt[s^(1<<x)][y] - gt[s][y];
                        int aa = min(20, i + tmp[0]), dd = min(20, j + tmp[1]);
                        tmp[3] = (gt[s^(1<<x)][3] + Ms) / M - (gt[s][3] + Ms) / M;
                        for (int k = 0; k * A + aa <= 20 && k <= tmp[3]; k++) {
                            for (int l = 0; l * D + dd <= 20 && k + l <= tmp[3]; l++) {
                                dp[s^(1<<x)][k * A + aa][l * D + dd] = max(dp[s^(1<<x)][k * A + aa][l * D + dd], dp[s][i][j] + 1ll * (tmp[3] - k - l) * H + tmp[2] - ct);
                            }
                        }
                    }
                }
            }
        }
        ll ans = -1;
        for (int i = 0; i <= 20; i++)
            for (int j = 0; j <= 20; j++)
                ans = max(ans, dp[(1<<7) - 1][i][j]);
        printf("%lld\n", ans);
    }
    return 0;
}

/*
1
4 4
S012
###M
###4
H365
1 1
1 1
1 1
98 1
1 1
1 1
1 1
0 0 100 1
1 1 5 1
1 1 10 1
*/

