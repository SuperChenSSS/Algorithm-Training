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

const int maxn = 1e6;
const int mod = 1e9 + 7;
int cnt[maxn + 10];
int inc[maxn + 10];
int g[maxn + 10];
int phi[maxn + 10];

inline void update(int &x, int y) {
    x = (x + y) % mod;
}

void work(int x) {
    for (int i = x; i < maxn; i += x) {
        int j = min(maxn - 1, i + x - 1);
        int k = i / x;
        update(cnt[i], 1LL * k * (k + 1) / 2 % mod * x % mod);
        update(cnt[j + 1], -1LL * k * (k + 1) / 2 % mod * x % mod);
        update(inc[i], k + 1);
        update(inc[j + 1], -(k + 1));
        update(cnt[j + 1], -1LL * (j - i + 1) * (k + 1) % mod);
    }
}

void calc() {
    int cur = 0;
    int x = 0;
    for (int i = 0; i < maxn; i++) {
        update(cur, cnt[i]);
        update(cur, x);
        g[i] = cur;
        update(x, inc[i]);
    }
}

int tail;
int prime[maxn], miu[maxn];
bool notprime[maxn];
void sieve() {
    miu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!notprime[i]) prime[tail++] = i, miu[i] = -1, phi[i] = i - 1;
        for (int j = 0; prime[j] * i < maxn; j++) {
            notprime[ prime[j] * i ] = true;
            miu[ prime[j] * i ] = -miu[i];
            if (i % prime[j] == 0) {
                miu[i * prime[j]] = 0; 
                phi[ i * prime[j] ] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    //cout << " H" << endl;
    for (int i = 1; i < maxn; i++) miu[i] += miu[i - 1];
    for (int i = 1; i < maxn; i++) phi[i] = (phi[i] + phi[i - 1]) % mod;
}

int main(int argc, char **argv) {
    for (int i = 1; i < maxn; i++) work(i);
    calc();
    sieve();


    //for (int i = 1; i < 10; i++) cout << phi[i] << endl;

    int n;
    while (scanf("%d", &n) != EOF) {
        assert(n >= 1 && n <= 1000000);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int j = n / (n / i);
            update(ans, 1LL * (miu[j] - miu[i - 1]) * g[n / i] % mod);
            i = j;
        }
        //cout << ans << ' ';
        ans = (ans - phi[n]) % mod;
        cout << (ans + mod) % mod << endl;
    }
    return 0;
}
