#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define N 100000

const int inf = 0x7fffffff;
const double ln2 = log(2.);

struct Edge {int v, w, r;};

int T, n, m, q, a, x, y;
int cnt, l[N + 9], r[N + 9], ll[N + 9], rr[N + 9], d[N + 9];
int rad[N + 9], f[N + 9], rt[N + 9];
vector<int> adj[N + 9];
vector<Edge> lnk[N + 9];
bool up[N + 9];

int log2(int x) {
	int n = 0;
	while (x >>= 1) ++n;
	return n;
}

int find(int e) {
	return f[e] == e? e : f[e] = find(f[e]);
}

void join(int a, int b) {
	f[a] = b;
}

struct Seg {int l, r, v;} S[4 * N + 9];
int tag[4 * N + 9];

void dfs(int root, int fa, int u, int dis) {
	rt[u] = root;
	d[l[u] = ++cnt] = dis;
	for (const auto &e: lnk[u])
		if (e.v == fa) {
			up[e.w] = true;
		} else {
			ll[e.w] = min(ll[e.w], cnt + 1);
			dfs(root, u, e.v, dis + e.r);
			rr[e.w] = max(rr[e.w], cnt);
		}
	r[u] = cnt;
}

void con(int k, int l, int r) {
	tag[k] = 0;
	S[k].l = l, S[k].r = r;
	if (l == r) {
		S[k].v = d[l];
		return;
	}
	int m = (l + r) >> 1;
	con(2 * k + 1, l, m);
	con(2 * k + 2, m + 1, r);
	S[k].v = max(S[2 * k + 1].v, S[2 * k + 2].v);
}

void down(int k) {
	if (tag[k]) {
		S[2 * k + 1].v += tag[k];
		tag[2 * k + 1] += tag[k];
		S[2 * k + 2].v += tag[k];
		tag[2 * k + 2] += tag[k];
		tag[k] = 0;
	}
}

int que(int k, int l, int r) {
	if (l <= S[k].l && S[k].r <= r)
		return S[k].v;
	down(k);
	int m = (S[k].l + S[k].r) >> 1;
	int ret = -inf;
	if (l <= m) ret = max(ret, que(2 * k + 1, l, r));
	if (r > m) ret = max(ret, que(2 * k + 2, l, r));
	return ret;
}

void add(int k, int l, int r, int d) {
	if (l <= S[k].l && S[k].r <= r) {
		S[k].v += d;
		tag[k] += d;
		return;
	}
	down(k);
	int m = (S[k].l + S[k].r) >> 1;
	if (l <= m) add(2 * k + 1, l, r, d);
	if (r > m) add(2 * k + 2, l, r, d);
	S[k].v = max(S[2 * k + 1].v, S[2 * k + 2].v);
}

void write(int k) {
	//printf("%d\n", k);
	printf("%.3f\n", k * ln2);
}

int main() {
	for (int Case = 1; scanf("%d%d%d", &n, &m, &q) == 3; ++Case) {
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
			rt[i] = 0;
			ll[i] = inf;
			rr[i] = 0;
			up[i] = false;
			adj[i].clear();
			lnk[i].clear();
			scanf("%d", rad + i);
			rad[i] = log2(rad[i]);
		}
		while (m--) {
			scanf("%d%d%d", &a, &x, &y);
			if (a == 1) {
				adj[x].push_back(y);
				adj[y].push_back(x);
			} else if (a == 2) {
				join(find(x), find(y));
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (auto j: adj[i]) {
				lnk[find(i)].push_back((Edge){find(j), i, rad[i] - rad[j]});
			}
		}
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			int f = find(i);
			if (f == i && !rt[f])
				dfs(f, 0, f, 0);
		}
		con(0, 1, cnt);
		printf("Case #%d:\n", Case);
		while (q--) {
			scanf("%d%d%d", &a, &x, &y);
			y = log2(y);
			if (a == 1) {
				int d = y - rad[x];
				int f = find(x);
				if (up[x]) add(0, l[f], r[f], -d);
				if (ll[x] <= rr[x]) add(0, ll[x], rr[x], +d);
				rad[x] = y;
			} else if (a == 2) {
				x = find(x);
				write(y - que(0, l[x], l[x]) + que(0, l[rt[x]], r[rt[x]]));
			}
		}
	}
	return 0;
}
