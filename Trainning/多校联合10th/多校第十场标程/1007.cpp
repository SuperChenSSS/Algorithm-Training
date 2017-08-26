#include <bits/stdc++.h>
using namespace std;
int tn[] = {11,80,758,9163,135607,2376341,48122413};
int pw[] = {27,256,3125,46656,823543,16777216,387420489};

int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int n, a, m, b; scanf("%d%d%d%d", &n, &a, &m, &b);
		int flg = 0;
		if (n > m) swap(n, m), swap(a, b), flg = 1;
		if (n == m) {
			if (n == 1) {
				puts("=");
				continue;
			}
			if (a == b) puts("=");
			if (a > b) printf("%c\n", '>'-2*flg);
			if (a < b) printf("%c\n", '<'+2*flg);
			continue;
		}
		if (n == 1 or b >= a) {
			printf("%c\n", '<'+2*flg);
			continue;
		}
		if (n >= 10) {
			printf("%c\n", '>'-2*flg);
			continue;
		}
		if (n > 2) {
			if (a - b > 1) {
				printf("%c\n", '>'-2*flg);
				continue;
			}
			if (b > 1) printf("%c\n", m > tn[n-3] ? '<'+2*flg : '>'-2*flg);
			if (b == 1) {
				if (m == pw[n-3]) puts("=");
				else printf("%c\n", m > pw[n-3] ? '<'+2*flg : '>'-2*flg);
			}
			continue;
		}
		if (a - b > 3) {
			printf("%c\n", '>'-2*flg);
			continue;
		}
		if (a - b == 3) {
			if (b == 1) {
				int p16 = 65536;
				if (m == p16) puts("=");
				else printf("%c\n", m > p16 ? '<'+2*flg : '>'-2*flg);
			}
			else printf("%c\n", m > 5297 ? '<'+2*flg : '>'-2*flg);
			continue;
		}
		if (a - b == 2) {
			if (b == 1) {
				if (m == 16) puts("=");
				else printf("%c\n", m > 16 ? '<'+2*flg : '>'-2*flg);
			} 
			else if (b == 2) printf("%c\n", m > 6 ? '<'+2*flg : '>'-2*flg);
			else printf("%c\n", m > 5 ? '<'+2*flg : '>'-2*flg);
			continue;
		}
		if (a - b == 1) {
			if (b == 1) {
				if (m == 4) puts("=");
				else printf("%c\n", m > 4 ? '<'+2*flg : '>'-2*flg);
			}
			else printf("%c\n", '<'+2*flg);
		}
	}
}

