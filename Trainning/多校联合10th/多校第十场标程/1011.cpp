#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;

struct Edge {
	int from, to;
	Edge( int f = 0, int t = 0 ) : from(f), to(t) {
		if( f > t )	swap( f, t );
	}
};

bool operator < ( const Edge& a, const Edge& b ) {
	if( a.from != b.from )	return a.from < b.from;
	return a.to < b.to;
}

void shortestPath( int from, LL d[], int prv[], vector<PII> g[], int n ) {
	priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
	while( !pq.empty() )	pq.pop();
	for(int i = 1; i <= n; i++ )	d[i] = -1;
	d[from] = 0;
	prv[from] = from;
	pq.push( mp( d[from], from ) );
	while ( !pq.empty() ) {
		PLI now = pq.top();
		pq.pop();
		for( PII nxt : g[now.second] ) {
			int v = nxt.first;
			int w = nxt.second;
			if( d[v] == -1 ) {
				d[v] = now.first + w;
				pq.push( mp( d[v], v ) );
				prv[v] = now.second;
				continue;
			}
			if( d[v] > now.first + w ) {
				d[v] = now.first + w;
				pq.push( mp( d[v], v ) );
				prv[v] = now.second;
			}
		}
	}
}

const int MAXN = 100006;
vector<PII> g[MAXN];
int prv[MAXN];
LL d1[MAXN], d2[MAXN];
set<Edge> used;
set<Edge> chk;
vector<int> usedw;

void addEdge( int& u, int& v, int& w ) {
	g[u].emplace_back( v, w );
	g[v].emplace_back( u, w );
}

int main() {
	//freopen("paths.in", "r", stdin );
	//freopen("paths.out", "w", stdout );
	int n, m;
	int T;
	scanf("%d", &T);
	while(T--) {
		assert(scanf("%d%d", &n, &m) == 2);
		chk.clear();
		assert( 1 <= n and n <= 100000 );
		assert( 1 <= m and m <= 100000 );
		for(int i = 1; i <= n; i++ )	g[i].clear();
		for(int i = 1; i <= m; i++ ) {
			int u, v, w;
			assert( scanf("%d%d%d", &u, &v, &w ) == 3 );
			addEdge( u, v, w );
			assert( u >= 1 and u <= n );
			assert( v >= 1 and v <= n );
			assert( w >= 1 and w <= 1000000000 );
			assert( u != v );
			assert( chk.count( Edge( u, v ) ) == 0 );
			chk.insert( Edge( u, v ) );
		}
		shortestPath( n, d2, prv, g, n );
		shortestPath( 1, d1, prv, g, n );
		int to = n;
		used.clear();
		usedw.clear();
		while( to != 1) {
			int from = prv[to];
			used.insert( Edge( from, to ) );
			usedw.push_back(d1[to] - d1[from]);
			to = from;
		}
		LL ans = (1LL << 60 );
		for(int u = 1; u <= n; u++ ) {
			for( PII dst : g[u] ) {
				int v = dst.first;
				if( !used.count( Edge( u, v ) ) ) {
					if( ~d1[u] and ~d2[v] ) {
						ans = min( ans, d1[u] + d2[v] + dst.second );
					}
				}
			}
		}
		for (auto item : usedw) {
			LL tmp = d1[n] + item * 2;
			ans = min(ans, tmp);
		}
		if( ans == (1LL << 60 ) )	assert(0);
		else	printf("%lld\n", ans );
	}
	return 0;
}
