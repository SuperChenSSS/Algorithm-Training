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

const int maxn = 1e3 + 10;

int a[maxn];
char b[maxn];

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        long long k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        assert(a[1] == 1);
        assert(b[1] == 'N');
        long long uplimit = 1, downlimit = -1;
        long long exactlimit = 1;
        for (int i = 2; i <= n; i++) {
            //cout << i << ' ' << a[i] << ' ' << b[i] << endl;
            //cout << uplimit << ' ' << downlimit << endl;
            assert(a[i] >= 0 && a[i] <= 1000);
            if (b[i] == 'N') {
                assert(a[i] <= exactlimit);
                uplimit += a[i], downlimit -= a[i];
                exactlimit += a[i];
            }
            if (b[i] == 'L') {
                assert(a[i] <= uplimit);
                uplimit += a[i];
            }
            if (b[i] == 'D') {
                assert(a[i] <= -downlimit);
                downlimit -= a[i];
            }
        }

        if (k >= downlimit && k <= uplimit) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
