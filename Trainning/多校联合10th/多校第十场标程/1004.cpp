#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int modExp(int a, int n) {
	int ret = 1;
	for(; n; n /= 2, a = 1LL * a * a % MOD) if(n & 1) ret = 1LL * ret * a % MOD;
	return ret;
}

int n, p[MAXN], reachable_count[MAXN], ring_size[MAXN], extra_size[MAXN], tot[MAXN];
int chk[MAXN], T, deg[MAXN];
bool notvanguard[MAXN], vis[MAXN];

void dfs(int u) {
	int v = p[u];
	if(ring_size[v]) {
		tot[chk[v]] += extra_size[u];
		return;
	}
	extra_size[v] += extra_size[u];
	deg[v]--;
	if(!deg[v]) {
		extra_size[v]++;
		dfs(v);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif	
	int ncase;
	for(scanf("%d", &ncase); ncase--; ) {
		assert(ncase <= 10); 
		scanf("%d", &n);
		assert(n <= 100000);
		memset(vis, 0, sizeof vis);
		memset(tot, 0, sizeof tot);
		memset(extra_size, 0, sizeof extra_size);
		memset(ring_size, 0, sizeof ring_size);
		memset(reachable_count, 0, sizeof reachable_count);
		memset(notvanguard, 0, sizeof notvanguard);
		memset(deg, 0, sizeof deg);
		memset(chk, 0, sizeof chk);
		T = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", p + i);
			assert(1 <= p[i] && p[i] <= n);
			deg[p[i]]++;
		}
		for(int i = 1; i <= n; i++) {
			notvanguard[p[i]] = true;
			if(vis[i] || ring_size[i]) continue;
			T++;
			chk[i] = T;
			vis[i] = true;
			int current_girl = i;
			while(1) {
				current_girl = p[current_girl];
				if(chk[current_girl] == T) {
					int lying_girl = current_girl;
					int sz = 0;
					int tt = 0;
					while(1) {
						current_girl = p[current_girl];
						sz++;
						if(current_girl == lying_girl) break;
					}
					while(1) {
						current_girl = p[current_girl];
						ring_size[current_girl] = sz;
						if(current_girl == lying_girl) break;
					}
					break;
				}
				if(vis[current_girl]) break;
				vis[current_girl] = true;
				chk[current_girl] = T;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(notvanguard[i] || ring_size[i]) continue;
			extra_size[i] = 1;
			dfs(i);
		}
		for(int i = 1; i <= n; i++) {
			if(ring_size[i]) {
				reachable_count[i] = ring_size[i] + tot[chk[i]];
			}
			else reachable_count[i] = extra_size[i];
			//cerr<<reachable_count[i]<<endl;
		}
		int ret = 0;
		for(int i = 1; i <= n; i++) ret = (ret + 1 + MOD - modExp(reachable_count[i] + 1, MOD - 2)) % MOD;
		ret++;
		ret %= MOD;
		printf("%d\n", ret);
	}
	return 0;
}
