#include <cstdio>
#include <cstring>
const int maxn = 1001, maxk = 100001;
int n, m, tot, lnk[maxn], dsu[maxn], fa[maxn], dep[maxn], eval[maxn], cnt, sum, ans;
struct Edge {
	int nxt, v, w;
} e[maxn << 1 | 1];
struct NonTreeEdge {
	int u, v, w;
} que[maxn >> 1 | 1];
int f[3][maxk], cur, pre = 1;
int dsu_find(int u) {
	return dsu[u] < 0 ? u : dsu[u] = dsu_find(dsu[u]);
}
bool dsu_merge(int u, int v) {
	u = dsu_find(u);
	v = dsu_find(v);
	if(u == v)
		return 0;
	if(dsu[u] < dsu[v]) {
		dsu[v] = u;
	} else if(dsu[v] < dsu[u]) {
		dsu[u] = v;
	} else {
		--dsu[u];
		dsu[v] = u;
	}
	return 1;
}
void dfs(int u) {
	for(int it = lnk[u]; it != -1; it = e[it].nxt) {
		int v = e[it].v, w = e[it].w;
		if(v == fa[u])
			continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		eval[v] = w;
		dfs(v);
	}
}
int idx[maxn];
struct PriorityQueue {
	int size, seq[maxn], pos[maxn];
	void push(int val, int idx) {
		++size;
		int p = size >> 1, c = size;
		while(p && seq[p] < val) {
			seq[c] = seq[p];
			pos[c] = pos[p];
			c = p;
			p >>= 1;
		}
		seq[c] = val;
		pos[c] = idx;
	}
	void topAndPop(int &val, int &idx) {
		val = seq[1];
		idx = pos[1];
		int p = 1, c = 2;
		while(c < size) {
			if(c + 1 < size && seq[c] < seq[c + 1])
				++c;
			if(seq[size] < seq[c]) {
				seq[p] = seq[c];
				pos[p] = pos[c];
			} else {
				break;
			}
			p = c;
			c <<= 1;
		}
		seq[p] = seq[size];
		pos[p] = pos[size--];
	}
} Q;
int main() {
	for(int Case = 1; scanf("%d%d", &n, &m) == 2; ++Case) {
		tot = cnt = sum = ans = 0;
		memset(lnk + 1, -1, n * sizeof(int));
		memset(dsu + 1, -1, n * sizeof(int));
		while(m--) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			sum += w;
			if(dsu_merge(u, v)) {
				e[tot] = (Edge){lnk[u], v, w};
				lnk[u] = tot++;
				e[tot] = (Edge){lnk[v], u, w};
				lnk[v] = tot++;
			} else {
				que[cnt++] = (NonTreeEdge){u, v, w};
			}
		}
		dfs(1);
		scanf("%d", &m);
		f[cur][0] = 1;
		f[cur][1] = 0;
		for(int i = 0; i < cnt; ++i) {
			int u = que[i].u, v = que[i].v, &sz = f[2][0] = 1;
			f[2][1] = que[i].w;
			for( ; dep[u] > dep[v]; u = fa[u])
				f[2][++sz] = eval[u];
			for( ; dep[u] < dep[v]; v = fa[v])
				f[2][++sz] = eval[v];
			for( ; u != v; u = fa[u], v = fa[v]) {
				f[2][++sz] = eval[u];
				f[2][++sz] = eval[v];
			}
			pre ^= 1;
			cur ^= 1;
			Q.size = 0;
			for(int j = 1; j <= sz; ++j) {
				idx[j] = 1;
				Q.push(f[2][j] + f[pre][1], j);
			}
			for(int &j = f[cur][0] = 0; j < m && Q.size; ) {
				int val, pos;
				Q.topAndPop(val, pos);
				f[cur][++j] = val;
				if(idx[pos] < f[pre][0]) {
					val = f[2][pos] + f[pre][++idx[pos]];
					Q.push(val, pos);
				}
			}
		}
		for(int i = f[cur][0], j = 0; i > 0; --i) {
			j += sum - f[cur][i];
			ans += j;
		}
		printf("Case #%d: %u\n", Case, ans);
	}
	return 0;
}
