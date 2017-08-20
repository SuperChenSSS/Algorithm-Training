#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define debug printf("%s %d\n", __FUNCTION__, __LINE__)
const int inf = 2147483647;

const int maxn = 100000 + 10;


int main(int argc, char **argv) {
    int cases;
    int u, v, w;
    int n, m, k;
    scanf("%d", &cases);
    while (cases--) {
        int ans = 0;
        scanf("%d%d", &n, &m);
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if ((u + v) % 2 != (n + m) % 2) ans ^= w;
            //cout << u << ' ' << v << ' ' << n << ' ' << m << ' ' << ans << endl;
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= m);
            assert(0 <= w <= 1000000000);
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &u, &v);
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= m);
            assert((u + v) % 2 != (n + m) % 2);
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &u, &v);
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= m);
            assert((u + v) % 2 == (n + m) % 2);
        }
        if (ans) printf("win\n");
        else printf("lose\n");
    }
    return 0;
}
