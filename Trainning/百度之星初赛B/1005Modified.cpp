#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define fir first
#define se second
#define LL long long
const int maxn = 1000;
const int maxm = 10000;
const int list = (1 << 30) - 1;
long long ans;
int n, m, dis[maxn], lnk[maxn], q[maxn], inq[maxn], pre[maxn], tot = 0, e;
int to[maxm], fw[maxm], ct[maxm], nxt[maxm];
void add(int u, int v, int flow, int w)
{
	nxt[e] = lnk[u];
	lnk[u] = e;
	to[e] = v;
	fw[e] = flow;
	ct[e++] = w;
	nxt[e] = lnk[v];
	lnk[v] = e;
	to[e] = u;
	fw[e] = 0;
	ct[e++] = -w;
}
void spfa()
{
	for (int i = 0; i <= n + 1; i++)
		dis[i] = list;
	dis[0] = 0;
	int h = 0, t = 1;
	q[0] = 0;
	while (h != t) {
		int v = q[h++];
		inq[v] = 0;
		if (h == maxn)
			h = 0;
		for (int i = lnk[v]; ~i; i = nxt[i])
			if (fw[i] && dis[v] + ct[i] < dis[to[i]]) {
				dis[to[i]] = dis[v] + ct[i];
				pre[to[i]] = i;
				if (!inq[to[i]]) {
					inq[to[i]] = 1;
					q[t++] = to[i];
					if (t == maxn)
						t = 0;
				}
			}
	}
}
void solve()
{
	spfa();
	while (dis[n + 1] != list) {
		if (dis[n + 1] > 0)
			break;
		int u = n + 1, mxfw = list;
		while (u) {
			if (fw[pre[u]] < mxfw)
				mxfw = fw[pre[u]];
			u = to[pre[u] ^ 1];
		}
		u = n + 1;
		while (u) {
			fw[pre[u]] -= mxfw;
			fw[pre[u] ^ 1] += mxfw;
			u = to[pre[u] ^ 1];
		}
		ans += 1LL * dis[n + 1] * mxfw;
		spfa();
	}
}
int main()
{
	while (cin>>n>>m) 
	{
		memset(lnk, -1, sizeof(lnk));
		e = 0;
		ans = 0;
		for (int i = 1, a, b, c, d; i <= n; i++) {
			cin>>a>>b>>c>>d;
			add(0, i, b, a);
			add(i, n + 1, d, -c);
		}
		for (int i = 1, u, v, k; i <= m; i++) {
			cin>>u>>v>>k;
			add(u, v, list, k);
			add(v, u, list, k);
		}
		solve();
		cout<<-ans<<"\n";
	}
}