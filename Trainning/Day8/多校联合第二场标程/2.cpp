
#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int cas;
inline unsigned sfr(unsigned h, unsigned x) {
    return h >> x;
}
int f(LL i, LL j) {
    LL w = i * 1000000ll + j;
    int h = 0;
    for(int k = 0; k < 5; ++k) {
        h += (int) ((w >> (8 * k)) & 255);
        h += (h << 10);
        h ^= sfr(h, 6);
    }
    h += h << 3;
    h ^= sfr(h, 11);
    h += h << 15;
    return sfr(h, 27) & 1;
}
char c[1100][1100];
int a[1100][1100];
LL b[1010][1010];
const int sz = 7, stride=550;
int en;
struct node {
    LL h;
    int x, y;
    bool operator < (const node&e ) const {
        if(h == e.h) {
            if(x == e.x)
                return y < e.y;
            return x < e.x;
        }
        return h < e.h;
    }
};
bool check(int top, int left) {
   // printf("check: %d, %d\n", top, left);
    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            if(f(i + top, j + left) != c[i][j])
                return false;
        }
    }
    en=1;
    printf("Case #%d :%d %d\n", cas, top, left);
    return true;
}
vector<node> v;
int main() {
//    freopen("01.in", "r", stdin);
//    freopen("01.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for (cas=1; cas<=T; cas++) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 0; i < 1000; ++i) {
            scanf("%s", c[i]);
            for(int j = 0; j < 1000; ++j) {
                c[i][j] -= '0';
            }
            LL x = 0;
            for(int j = 0; j < sz; ++j)
                x = (x << 1) + c[i][j];
            for(int j = 0; j <= 1000 - sz; ++j) {
                a[i][j] = x;
                x = (x << 1) + c[i][j + sz];
                x -= c[i][j] << sz;
            }
        }
        for(int j = 0; j <= 1000 - sz; ++j) {
            LL x = 0;
            for(int i = 0; i < sz; ++i)
                x = (x << sz) + a[i][j];
            for(int i = 0; i <= 1000 - sz; ++i) {
                b[i][j] = x;
                x = (x << sz) + a[i + sz][j];
                x -= 1ll * a[i][j] << (sz * sz);
            }
        }
        v.clear();
        node tmp;
        for(int i = 0; i <= 1000 - sz; ++i) {
            for(int j = 0; j <= 1000 - sz; ++j) {
                tmp.h = b[i][j];
                tmp.x = i;
                tmp.y = j;
                v.push_back(tmp);
                LL x = 0;
                for(int ii = 0; ii < sz; ++ii)
                    for(int jj = 0; jj < sz; ++jj)
                        x = (x<<1) + c[ii+i][jj+j];
                assert(x == b[i][j]);
            }
        }
        //    for(int i = 0; i < sz; ++i) {
        //        for(int j = 0; j < sz; ++j) {
        //            cout << (int)c[i][j];
        //        }
        //        cout << endl;
        //    }
        sort(v.begin(), v.end());
        en=0;
        for(int i = 1; i <= 1000001 - sz; i += stride) {
            if (en==1) break;
            for(int j = 1; j <= 1000001 - sz; j += stride) {
                if (en==1) break;
                LL x = 0;
                for(int ii = 0; ii < sz; ++ii) {
                    for(int jj = 0; jj < sz; ++jj) {
                        x = (x<<1) + f(i + ii, j + jj);
                        //                    cout << f(i +ii, j +jj);
                    }
                    //                cout << endl;
                }
                auto it = lower_bound(v.begin(), v.end(), (node) {
                    x, 0, 0
                });
                for(; it != v.end() && it->h == x; ++it) {
                    LL y = 0;
                    for(int ii = 0; ii < sz; ++ii) {
                        for(int jj = 0; jj < sz; ++jj)
                            y = (y << 1) + c[ii + it->x][jj + it->y];
                    }
                    //assert(x == y);
                    if(check(i - it->x, j - it->y))
                        break;
                }
            }
        }
    }
    return 0;
}
