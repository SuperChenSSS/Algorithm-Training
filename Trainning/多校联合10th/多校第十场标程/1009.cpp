#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
const int M = 200, N = M+M;
int gcd[N][N], no[N][N], r[N*N], id[N*N], po[N*N], chk[N][N];
pii P[5010];
vector<pii> V0, V, sw[50000];

int main() {
	V0.push_back(pii(1, 0));
	for (int i = 1; i <= M; i++) {
		gcd[i][0] = gcd[0][i] = i;
		for (int j = 1; j <= M; j++) {
			int d = __gcd(i, j), x, y;
			gcd[i][j] = d, x = i/d, y = j/d;
			if (chk[x][y]) continue;
			chk[x][y] = 1, V0.pb(pii(x, y));
		}
	}
	sort(V0.begin(), V0.end(), [](pii a, pii b){return a.y*b.x < a.x*b.y;});
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < V0.size(); j++) V.pb(V0[j]), swap(V0[j].x, V0[j].y), V0[j].x *= -1;
	}
	for (int i = 0; i < V.size(); i++) no[V[i].x+M][V[i].y+M] = i;
	int T;
	for (scanf("%d", &T); T--;) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d%d", &P[i].x, &P[i].y);
		sort(P, P+n);
		for (int i = 0; i < V.size(); i++) sw[i].clear();
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				int dx = P[i].x-P[j].x, dy = P[i].y-P[j].y, d = gcd[abs(dx)][abs(dy)];
				dx /= d, dy /= d;
				if (dx > 0 || (!dx && dy < 0)) sw[no[M-dy][M+dx]].pb(pii(j, i));
				else sw[no[M+dy][M-dx]].pb(pii(i, j));
 			}
		}
		int cnt = 0, tot = 0;
		vector<int> vt;
		for (int i = 0; i < n; i++) cnt += P[i]<pii(0, 0), po[i]=i, id[i]=i;
		r[tot++] = id[cnt]; vt.pb(id[n-cnt-1]);
		for (int i = 1; i < V.size(); i++) {
			for (int j = 0; j < sw[i].size(); j++) {
				int a=sw[i][j].x, b=sw[i][j].y;
				if ((P[a].x-P[b].x)*V[i].y <= 0 && 0 <= (P[a].y-P[b].y)*V[i].x)
					id[po[a]] = b, id[po[b]] = a, swap(po[a], po[b]);
			}
			if (r[tot-1] != id[cnt]) r[tot++] = id[cnt];
			vt.pb(id[n-cnt-1]);
		}
		for (int i = 0; i < vt.size(); i++) if (r[tot-1] != vt[i]) r[tot++] = vt[i];
		while (r[tot-1]==r[0]) --tot;
		int q, k;
		for (scanf("%d", &q); q --;) {
			scanf("%d", &k); k %= tot;
			printf("%d %d\n", P[r[k]].x, P[r[k]].y);
		}
	}
	return 0;
}

