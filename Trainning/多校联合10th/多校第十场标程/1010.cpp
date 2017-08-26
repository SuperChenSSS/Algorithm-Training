#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
multiset<PII> s;
PII seg[111111];

#define FI(n) FastIO::read(n)

namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;
		 
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int ncase = 0;
	for (FI(ncase); ncase--; ) {
		int n; FI(n);
		long long ss = 0;
		for (int i = 0; i < n; i++) FI(seg[i].first), FI(seg[i].second), ss += seg[i].second - seg[i].first, assert(seg[i].second - seg[i].first > 0);
		sort(seg, seg + n);
		s.clear();
		s.insert(PII(1e9 + 1, 1e9));
		int res = 0;
		set<PII> :: iterator it;
		for (int i = 0; i < n; i++) {
			it = s.upper_bound(seg[i]);
			if (it == s.begin()) {
				res++;
				s.insert(PII(seg[i].second, seg[i].first));
				continue;
			}
			it--;
			ss += seg[i].first - it->first;
			s.erase(it);
			s.insert(PII(seg[i].second, seg[i].first));
		}
		printf("%d %lld\n", res, ss);
	}
	
	return 0;
}
