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

const int mod = 1e9 + 7;
const int maxn = 2000 + 10;

int power(int x, int times) {
    int rt = 1;
    int base = x;
    while (times) {
        if (times & 1) rt = 1LL * rt * base % mod;
        base = 1LL * base * base % mod;
        times >>= 1;
    }
    return rt;
}


int dp[maxn][maxn];
void calc_dp(int n, int m) {
    dp[1][1] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(m, i); j++) {
            dp[i][j] = (1LL * dp[i - 1][j] * j + 1LL * dp[i - 1][j - 1] * (m - j + 1)) % mod;
        }
    }
}

int c[maxn][maxn];
int f[maxn];
int main(int argc, char **argv) {
    for (int i = 0; i < maxn; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) 
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    //cout << "H" << endl;
    int cases;
    int n, m;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d%d", &n, &m);
        assert(1 <= n && n <= 2000);
        assert(1 <= n && n <= 2000);
        int ans = 0;
        for (int i = 1; i < m; i++) {
            if (i > n) break;
            f[i] = power(i, n);
            for (int j = 1; j < i; j++) {
                f[i] = (f[i] - 1LL * c[i][j] * f[j]) % mod;
                //if (i == 3) {
                    //cout << f[i] << ' ' << aoe << ' ' << c[i][j] << ' ' << f[j] << endl;
                //}
            }
            //cout << f[i] << ' ' << c[m][i] << ' ' << power(m - i, n) << endl;
            //cout << f[i] << ' ' << c[m][i] << ' ' << power(m - i, n) << ' ' << f[i] * c[m][i] * power(m - i, n) << endl;
            ans = (ans + 1LL * f[i] * c[m][i] % mod * power(m - i, n)) % mod;
        }

        calc_dp(n, m);
        int dp_ans = 0;
        for (int i = 1; i < m; i++) {
            int c = dp[n][i];
            for (int j = 0; j < n; j++) 
                c = 1LL * c * (m - i) % mod;

            //cout << c << endl;
            dp_ans = (dp_ans + c) % mod;
        }

        //cout << f[1] * c[m][1] << ' ' << dp[n][1] << endl;
        //cout << f[2] * c[m][2] << ' ' << dp[n][2] << endl;

        //printf("%d\n", dp_ans);
        //cout << f[1] << ' ' << f[2] << endl;
        ans = (ans + mod) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
