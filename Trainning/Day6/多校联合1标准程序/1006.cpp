#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define M 1000000007

const int maxn = 100100;
int n, m, cal[2][maxn], a[maxn], b[maxn], ans = 1;
bool vis[maxn];

void dfs(int t, int l, int *a, int k){
	if(vis[t]){
		cal[k][l]++;
		return;
	}
	vis[t] = 1;
	dfs(a[t], l + 1, a, k);
}

int main(){
    int ca = 0;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < n; i++)
			scanf("%d", a + i);
		for(int i = 0; i < m; i++)
			scanf("%d", b + i);
		memset(cal, 0, sizeof(cal));
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < m; i++)
			if (!vis[i]) dfs(i, 0, b, 0);
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++)
			if (!vis[i]) dfs(i, 0, a, 1);
		ans = 1;
		for(int i = 1; i <= n; i++)
			if(cal[1][i]){
				int lim = (int)sqrt(i + 0.5), ta = 0;
				for(int j = 1; j <= lim; j++)
					if(i % j == 0){
						(ta += (ll)cal[0][j] % M * j % M) %= M;
						if (j * j != i) (ta += (ll)cal[0][i / j] % M * (i / j) % M) %= M;
					}
				for(int j = 1; j <= cal[1][i]; j++)
					ans = (ll)ans * ta % M;
			}
		printf("Case #%d: %d\n", ++ca, ans);
	}
  return 0;
}

