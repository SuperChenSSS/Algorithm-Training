#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;
const int MAXM = 1<<19;

int x[MAXN], y[MAXN];
int sx[MAXN], sy[MAXN];
int ex[MAXN], ey[MAXN];

int sum[MAXM], val[MAXM], add[MAXM];

vector<int> V[MAXN];

inline int f(int x) { return x^(x>>1); }

typedef unsigned int uint;

uint dp[33][33], g[256][256];

inline uint G(uint A, uint B) {
	uint a1 = A>>8, a2 = A&255;
	uint b1 = B>>8, b2 = B&255;
	uint c1 = g[a1][b1];
	uint c2 = g[a1^a2][b1^b2];
	uint c3 = g[a2][b2];
	return ((c2^c3) << 8)  | (g[c1][128] ^ c3);
}

inline uint H(uint A, uint B) {
	uint a1 = A>>16, a2 = A&65535;
	uint b1 = B>>16, b2 = B&65535;
	uint c1 = G(a1, b1);
	uint c2 = G(a1^a2, b1^b2);
	uint c3 = G(a2, b2);
	return ((c2^c3) << 16) | (G(c1, 32768) ^ c3);
}

inline void build(int u, int l, int r) {
	sum[u] = f(y[r]-1) ^ f(y[l-1]-1);
	val[u] = add[u] = 0;
	if (l == r) {
		return;
	}
	int mid = l+r >> 1;
	build(u+u, l, mid);
	build(u+u+1, mid+1, r);
}

inline void up(int u) {
	val[u] = min(val[u+u], val[u+u+1]);
	sum[u] = 0;
	if (val[u] == val[u+u]) sum[u] ^= sum[u+u];
	if (val[u] == val[u+u+1]) sum[u] ^= sum[u+u+1];
}

inline void down(int u) {
	if (add[u]) {
		val[u+u] += add[u], add[u+u] += add[u];
		val[u+u+1] += add[u], add[u+u+1] += add[u];
		add[u] = 0;
	}
}

inline void modify(int u, int l, int r, int ll, int rr, int x) {
	if (ll <= l && r <= rr) {
		val[u] += x, add[u] += x;
		return;
	}
	int mid = l+r >> 1;
	down(u);
	if (ll <= mid) modify(u+u, l, mid, ll, rr, x);
	if (mid < rr) modify(u+u+1, mid+1, r, ll, rr, x);
	up(u);
}

const int SIZE = 1<<16;
char ibuf[SIZE];

int ibufp = SIZE, ibufn = SIZE;

inline void read(int &n) {
	while (ibufn) {
		for (; ibufp < ibufn && ibuf[ibufp] <= ' '; ibufp++);
		if (ibufp < ibufn) break;
		ibufn = fread(ibuf, 1, SIZE, stdin), ibufp = 0;
	}
	n = 0;
	while (ibufn) {
		for (; ibufp < ibufn && ibuf[ibufp] > ' '; ibufp++) n = n * 10 + ibuf[ibufp] - '0';
		if (ibufp < ibufn) return;
		ibufn = fread(ibuf, 1, SIZE, stdin), ibufp = 0;
	}
}

int main() {
	int ncase;
	for (int i = 0; i < 32; i++) dp[0][i] = dp[i][0] = 1U<<i;
	for (int i = 1; i < 32; i++) {
		int k = i & -i;
		for (int j = 1; j < i; j++) dp[i][j] = dp[j][i];
		for (int j = i; j < 32; j++) {
			uint x = dp[i^k][j], &ret = dp[i][j];
			for (int l = 31; l >= 0; l--) if (x >> l & 1) {
				if (l & k) {
					ret ^= 1U<<l;
					ret ^= dp[k-1][l^k];
				} else {
					ret ^= 1U<<(l^k);
				}
			}
		}
	}
	for (int i = 0; i < 256; i++) {
		for (int k = 0; k < 8; k++) if (i >> k & 1) {
			for (int j = 0; j < 256; j++) {
				for (int l = 0; l < 8; l++) if (j >> l & 1) g[i][j] ^= dp[k][l];
			}
		}
	}
	for (read(ncase); ncase--; ) {
		int n, m; read(n), read(m);
		int xn = 0, yn = 0;
		x[xn++] = 1, x[xn++] = n+1;
		y[yn++] = 1, y[yn++] = n+1;
		for (int i = 0; i < m; i++) {
			read(sx[i]), read(sy[i]), read(ex[i]), read(ey[i]);
			ex[i]++, ey[i]++;
			x[xn++] = sx[i], x[xn++] = ex[i];
			y[yn++] = sy[i], y[yn++] = ey[i];
		}
		sort(x, x + xn);
		sort(y, y + yn);
		xn = unique(x, x + xn) - x;
		yn = unique(y, y + yn) - y;
		build(1, 1, yn-1);
		for (int i = 0; i < m; i++) {
			sx[i] = lower_bound(x, x + xn, sx[i]) - x;
			ex[i] = lower_bound(x, x + xn, ex[i]) - x;
			sy[i] = lower_bound(y, y + yn, sy[i]) - y;
			ey[i] = lower_bound(y, y + yn, ey[i]) - y;
			V[sx[i]].push_back(i);
			V[ex[i]].push_back(~i);
		}
		uint ans = 0;
		for (int i = 0; i < xn-1; i++) {
			for (auto k : V[i]) {
				if (k >= 0) modify(1, 1, yn-1, sy[k]+1, ey[k], 1);
				else k = ~k, modify(1, 1, yn-1, sy[k]+1, ey[k], -1);
			}
			int minv = val[1], sumy = f(n), sumx = f(x[i+1]-1) ^ f(x[i]-1);
			if (minv == 0) sumy ^= sum[1];
			ans ^= H(sumx, sumy);
		}
		for (int i = 0; i < xn; i++) V[i].clear();
		puts(ans ? "Yong Chol" : "Brother");
	}
	return 0;
}
