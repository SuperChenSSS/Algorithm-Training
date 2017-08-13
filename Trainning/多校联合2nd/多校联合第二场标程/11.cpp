#include <bits/stdc++.h>  
#define ll long long
#define mk make_pair
#define y1 yyy
using namespace std;

const int N = 1e3 + 5;

map< pair<int, int>, bool> M;  
int x[N], y[N], n, ans;

int main() {
	int T;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		M.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", x + i, y + i);
			M[mk(x[i], y[i])] = 1;
			
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int dx = y[j] - y[i];
				int dy = x[i] - x[j];
				int ok = 0; 
				if (M.count(mk(x[i] + dx, y[i] + dy))) ok++;
				if (M.count(mk(x[j] + dx, y[j] + dy))) ok++;
				if (ok == 2) ans++;
				ok = 0;
				if (M.count(mk(x[i] - dx, y[i] - dy))) ok++;
				if (M.count(mk(x[j] - dx, y[j] - dy))) ok++;
				if (ok == 2) ans++;
			}
		}
		printf("%d\n", ans / 4);
	}
} 
