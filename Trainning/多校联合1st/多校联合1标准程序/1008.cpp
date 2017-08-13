#include <cstdio>
#include <algorithm>

using namespace std;

int T, n, m, o[109], p[109];
unsigned s[10000009];
unsigned a[109];

unsigned x, y, z;

inline
unsigned xorshf96() {
	unsigned t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}

bool cmp(int a, int b) {
	return p[a] < p[b];
}

int main() {
	for (int Case = 1; scanf("%d%d%u%u%u", &n, &m, &x, &y, &z) == 5; ++Case) {
		for (int i = 0; i < m; ++i) {
			o[i] = i;
			scanf("%d", p + i);
		}
		for (int i = 0; i < n; ++i) s[i] = xorshf96();
		sort(o, o + m, cmp);
		p[o[m] = m] = n;
		for (int i = m - 1; ~i; --i) {
			if (p[o[i]] == p[o[i + 1]]) {
				a[o[i]] = a[o[i + 1]];
				continue;
			}
			nth_element(s, s + p[o[i]], s + p[o[i + 1]]);
			a[o[i]] = s[p[o[i]]];
		}
		printf("Case #%d: ", Case);
		for (int i = 0; i < m; ++i) printf("%u%c", a[i], " \n"[i == m - 1]);
	}
	return 0;
}
