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
typedef long long int64;
const int inf = 2147483647;
const int maxn = 1000000;
const int maxr = 1000000;
const int64 mod = 4179340454199820289;
const int g = 3;

inline int64 mul(int64 x, int64 y) {
    return (x * y - (long long)(x / (long double)mod * y + 1e-3) * mod + mod) % mod;
}

int64 power(int64 x, int64 times) {
    int64 rt = 1;
    int64 base = x;

    while (times) {
        if (times & 1) rt = mul(rt, base);
        base = mul(base, base);
        times >>= 1;
    }
    return rt;
}

const int maxbits = 57;
int64 wn[maxbits + 10];
void getwn() {  
    for(int i = 1; i <= maxbits; ++i) {  
        long long t = 1LL << i;  
        wn[i] = power(g, (mod - 1) / t);  
    }  
}  

void change(int64 *x, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(x[i], x[j]);
        int k = len / 2;
        while(j >= k) {
            j -= k;
            k /= 2;
        }
        j += k;
    }
}

void NTT(int64 *x, int len, int on) {
    change(x, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        for(int j = 0; j < len; j += h) {
            int64 w = 1;
            for(int k = j; k < j + h / 2; ++k) {
                int64 u = x[k];
                int64 t = mul(x[k + h / 2], w);
                x[k] = u + t;
                if(x[k] >= mod) x[k] -= mod;
                x[k + h / 2] = u - t + mod;
                if(x[k + h / 2] >= mod) x[k + h / 2] -= mod;
                w = mul(w, wn[id]);
            }
        }
    }
    if(on == -1) {
        for(int i = 1; i < len / 2; ++i) swap(x[i], x[len - i]);
        int64 inv = power(len, mod - 2);
        for(int i = 0; i < len; ++i)
            x[i] = mul(x[i], inv);
    }
}

int64 cur[maxr];
int64 rt[maxr];
int64 tmp[maxr];
//int64 a[8] = {1, 2, 3, 4, 0, 0, 0, 0};
//int64 b[8] = {4, 3, 2, 1, 0, 0, 0, 0};
//int64 c[8];
void output(int64 *x, int64 len) {
    for (int i = 0; i < len; i++) 
        cout << x[i] << ' ';
    cout << endl;
}
void polymul(int64 *x, int64 *y, int64 len, int64 base) {
    //output(x, len);
    //output(y, len);
    NTT(x, len, 1);
    if (y != x) NTT(y, len, 1);
    for (int i = 0; i < len; i++) x[i] = mul(x[i], y[i]);
    NTT(x, len, -1);
    //output(x, len);
    //cout << endl;

    for (int i = 0; i < len; i++) 
        if (x[i] >= base) {
            x[i + 1] += x[i] / base;
            x[i] %= base;
        }

}


int work(int L, long long times, int rk, int x, int base) {
    getwn();
    //NTT(a, 8, 1);
    //NTT(b, 8, 1);
    //for (int i = 0; i < 8; i++) c[i] = mul(a[i], b[i]);
    //NTT(c, 8, -1);
    //for (int i = 0; i < 8; i++) cout << c[i] << ' ';
    //cout << endl;
    //for (int i = 0; i < L; i++) cur[i] = 0;
    long long len = 1;
    while (len < L) len <<=1;
    len *= 2;

    cur[0] = x;
    for (int i = 1; i < len; i++) cur[i] = 0;

    rt[0] = 1;
    for (int i = 1; i < len; i++) rt[i] = 0;

    //output(rt, len);
    //cout << x << ' ' << base << endl;
    //cout << endl;
    times++;
    //cout << times << endl;
    //cout << times << endl;
    //cout << L << ' ' << rk << ' ' << base << endl;
    len = 2;
    while (times) {
        //cout << times << endl;
        if (times & 1) {
            for (int i = 0; i < len; i++) tmp[i] = cur[i];
            polymul(rt, tmp, len, base);
        } 
        polymul(cur, cur, len, base);

        //cout << (times & 1) << endl;
        //output(rt, len);
        //output(cur, len);
        len <<= 1;
        
        times >>= 1;
    }
    return rt[rk];
    //while (times--) {
        //for (int i = 0; i < L; i++) cur[i] *= x;
        //for (int i = 0; i < L; i++) {
            //if (cur[i] >= base) {
                //cur[i + 1] += cur[i] / base;
                //cur[i] %= base;
            //}
        //}
    //}
    //return cur[rk];
}

int p[maxn], r[maxn];

int main(int argc, char **argv) {
    int cases;
    int n;
    long long k;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d%lld", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", &p[i]);
        for (int i = 0; i < n; i++) {
            scanf("%d", &r[i]);
        }

        int L = 0;
        for (int i = 0; i < n; i++) L = max(L, r[i]);

        assert(1 <= k && k < 1LL * L * L);
        for (int i = 0; i < n; i++) {
            assert(L - 1 <= r[i] && r[i] <= L);
        }

        int base = 1, x = 1;
        for (int i = 0; i < n; i++) {
            base *= p[i];
            if (r[i] != L) x *= p[i];
        }
        assert(1 <= base <= 1000000);
        k--;
        printf("%d\n", work(L, k / L, L - 1 - k % L, x, base));
    }
    return 0;
}
