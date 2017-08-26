#include <bits/stdc++.h>

using namespace std;

long long pw[22];
int p[6][6];
int cur, now[2];
vector<pair<long long, int> > V[2][2];
vector<int> adj[22];
map<long long, int> H[2];
	
long long go(long long state, int source, int destination) {
	long long source_ship = state / pw[20 - source] % 6;
	long long destination_ship = state / pw[20 - destination] % 6; 
	long long result = state + (destination_ship - source_ship) * (pw[20 - source] - pw[20 - destination]);
	return result;
}

int traverse_by_level() {
	
	V[cur][!now[cur]].clear();
	for(int i = 0; i < V[cur][now[cur]].size(); i++) {
		pair<long long, int> C = V[cur][now[cur]][i];
		int pos_general = C.second;
		for(int j = 0; j < adj[pos_general].size(); j++) {
			int pos_soldier = adj[pos_general][j];
			pair<long long, int> N = make_pair(go(C.first, pos_general, pos_soldier), pos_soldier);
			if(H[cur][N.first]) continue;
			H[cur][N.first] = H[cur][C.first] + 1;
			if(H[!cur][N.first]) {
				return H[cur][N.first] + H[!cur][N.first] - 2;
			}
			V[cur][!now[cur]].push_back(N);
		}
	}
	now[cur] ^= 1;
	return -1;
}
int bidirectional_bfs(pair<long long, int> S, pair<long long, int> E) {
	H[0].clear();
	H[1].clear();
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) V[i][j].clear();
	cur = 0;
	now[0] = now[1] = 0;	
	if(S.first == E.first) return 0;
	V[0][0].push_back(S);
	V[1][0].push_back(E);
	H[0][S.first] = 1;
	H[1][E.first] = 1;
	int steps = -1;
	int deep = 0;
	while(1) {
		steps = traverse_by_level();
		if(steps != -1) return steps;
		cur ^= 1;
		deep++;
		if(deep == 20) return -1;
	}
	
}

void init() {
	for(int i = 0, c = 0; i < 6; i++)
		for(int j = 0; j <= i; j++) p[i][j] = c++;
	for(int i = 0; i < 6; i++)
		for(int j = 0; j <= i; j++) {
			if(i) {
				if(j) adj[p[i][j]].push_back(p[i - 1][j - 1]);
				if(j != i) adj[p[i][j]].push_back(p[i - 1][j]);
			}
			if(i != 5) {
				adj[p[i][j]].push_back(p[i + 1][j]);
				adj[p[i][j]].push_back(p[i + 1][j + 1]);
			}
		}
	pw[0] = 1;
	for(int i = 1; i < 22; i++) pw[i] = pw[i - 1] * 6;
		
}

int cnt[6];
int main() {
#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	init();
	int ncase;
	for(scanf("%d", &ncase); ncase--; ) {
		long long start = 0, goal = 0;
		int ship, pos_general;
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < 21; i++) {
			scanf("%d", &ship);
			cnt[ship]++;
			start = start * 6 + ship;
			if(ship == 0) pos_general = i;
		}
		for(int i = 0; i < 6; i++) assert(cnt[i] == i + 1);
		for(int i = 0; i < 6; i++)
			for(int j = 0; j <= i; j++) goal = goal * 6 + i;
		int res = bidirectional_bfs(make_pair(start, pos_general), make_pair(goal, 0));
		if(res == -1) {
			puts("too difficult");
			continue;
		}
		printf("%d\n", res);
	}
	return 0;	
}
