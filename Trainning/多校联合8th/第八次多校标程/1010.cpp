#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>
using namespace std;
#define debug printf("%s %d\n", __FUNCTION__, __LINE__)

const int maxn = 600002;
const int maxm = 600002;
const int inf = 2147483647;

struct Tedge {
	int v, next, f;
} e[maxm * 2];

int N;
int head[maxn];

void insert(int x, int y, int c) {
	e[N].v = y; e[N].next = head[x]; e[N].f = c;
	head[x] = N; N++; //if (N & 1) {
        //cout << x << ' ' << y << ' ' << c << endl;
    //}
	if (N & 1) insert(y, x, 0);
}

int st, ed;
int o[maxn], dis[maxn];

bool bfs() {
	for (int i = 1; i <= ed; i++) dis[i] = -1;
	o[0] = st; dis[st] = 0;
	for (int h = 0, t = 0; h <= t; h++) {
		int u = o[h];
		if (u == ed) return true;
		for (int i = head[u]; i != -1; i = e[i].next)
			if (e[i].f > 0 && dis[ e[i].v ] == -1) {
				o[++t] = e[i].v;
				dis[ e[i].v ] = dis[u] + 1;
			}
	}
	return false;
}

int dfs(int u, int limit) {
    //cout << u << ' ' << limit << endl;
	if (u == ed) return limit;
	int rt = 0;
	for (int i = head[u]; i != -1; i = e[i].next) 
		if (dis[ e[i].v ] == dis[u] + 1 && e[i].f > 0) {
            //cout << u << ' ' << e[i].v << ' ' << min(e[i].f, limit - rt) << endl;
			int tmp = dfs(e[i].v, min(e[i].f, limit - rt));
			e[i].f -= tmp;
			e[i ^ 1].f += tmp;
			rt += tmp;
			if (rt == limit) return rt;
		}	
	dis[u] = -1;
	return rt;
}

int aoe[maxn];
int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int n, W, p, q;
        scanf("%d%d%d%d", &n, &W, &p, &q);
        assert(1 <= n && n <= 500);
        assert(1 <= W && W <= 1000000);
        assert(0 <= p && p <= 1000);
        assert(0 <= q && q <= 1000);
        st = 0, ed = n + 1;
        N = 0;
        for (int i = st; i <= ed; i++) head[i] = -1, aoe[i] = 0;
       
        int x, y, z, a, b, c, d, e, f;
        for (int i = 1; i <= p; i++) {
            scanf("%d%d%d%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c, &d, &e, &f);
            assert(1 <= x && x <= n);
            assert(1 <= y && y <= n);
            assert(1 <= z && z <= n);
            assert(1 <= a && a <= 1000);
            assert(1 <= b && b <= 1000);
            assert(1 <= c && c <= 1000);
            assert(1 <= d && d <= 1000);
            assert(1 <= e && e <= 1000);
            assert(1 <= f && f <= 1000);
            insert(y, x, 4 * a);
            insert(z, y, 4 * b);
            insert(x, z, 4 * c);
            aoe[x] += (d - a) - (f - c);
            aoe[y] += (e - b) - (d - a);
            aoe[z] += (f - c) - (e - b);
        }
        for (int i = 1; i <= n; i++) aoe[i]++;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) 
            if (aoe[i] > 0) {
                insert(st, i, 2 * aoe[i]);
                ans -= aoe[i];
            }
            else if (aoe[i] < 0) {
                insert(i, ed, -2 * aoe[i]);
                ans += aoe[i];
            }

        int relation;
        for (int i = 1; i <= q; i++) {
            scanf("%d%d%d", &x, &y, &relation);
            if (relation == 0) insert(y, x, inf);
            if (relation == 1) insert(y, x, inf), insert(x, y, inf);
            if (relation == 2) insert(st, x, inf), insert(y, ed, inf);
        }

        //cout << ans << endl;
        while (bfs()) 
            ans += dfs(st, inf);
        //cout << ans << endl;
        cout << 1LL * ans * W << endl;
        //printf("%lld\n", 1LL * ans * W);
    }
	return 0;
} 
