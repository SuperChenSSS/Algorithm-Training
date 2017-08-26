#include <bits/stdc++.h>
using namespace std;

const int MAXN = 111111;
vector<int> adj[MAXN];
int dp[MAXN][2];

#define FI(n) FastIO::read(n)

namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;
		 
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};

int main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	
	int ncase;
	for (FI(ncase); ncase--; ) {
		int n, k;
		FI(n), FI(k);
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 2; i <= n; i++) {
			int x;
			FI(x);
			adj[x].push_back(i);
		}
		for (int i = n; i > 0; i--) {
			dp[i][0] = dp[i][1] = 0;
			int res = n + 1;
			for (int j = 0; j < adj[i].size(); j++) {
				int v = adj[i][j];
				dp[i][0] += dp[v][1];
				res = min(res, dp[v][1] - dp[v][0]);
			}
			if (res > n) continue;
			dp[i][1] = dp[i][0] - res + 1;
		}
		int t = dp[1][1];
		if (k <= 2 * t) k = (k + 1) / 2;
		else k -= t;
		printf("%d\n", k);
	}
	
	return 0;
}
