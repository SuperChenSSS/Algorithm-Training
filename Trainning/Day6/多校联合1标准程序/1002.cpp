#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100020;
const int Q = 1e9 + 7;
int n , L;
int num[26][N];
int power[N] , sum[N];
bool ban[26];

char str[N];
int a[26];

bool cmp(int A , int B) {
    for (int i = L - 1 ; i >= 0 ; -- i) {
        if (num[A][i] != num[B][i]) {
            return num[A][i] < num[B][i];
        }
    }
    return 0;
}

void work() {
    memset(num , 0 , sizeof(num));
    memset(ban , 0 , sizeof(ban));
    memset(sum , 0 , sizeof(sum));
    L = 0;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        int len = strlen(str);
        if (len > 1) {
            ban[str[0] - 'a'] = 1;
        }
        reverse(str , str + len);
        for (int j = 0 ; j < len ; ++ j) {
            ++ num[str[j] - 'a'][j];
            sum[str[j] - 'a'] += power[j];
            if (sum[str[j] - 'a'] >= Q) {
                sum[str[j] - 'a'] -= Q;
            }
        }
        L = max(L , len);
    }
    for (int i = 0 ; i < 26 ; ++ i) {
        for (int j = 0 ; j < L ; ++ j) {
            num[i][j + 1] += num[i][j] / 26;
            num[i][j] %= 26;
        }
        while (num[i][L]) {
            num[i][L + 1] += num[i][L] / 26;
            num[i][L ++] %= 26;
        }
        a[i] = i;
    }
    sort(a , a + 26 , cmp);
    int zero = -1;
    for (int i = 0 ; i < 26 ; ++ i) {
        if (!ban[a[i]]) {
            zero = a[i];
            break;
        }
    }
    int res = 0 , x = 25;
    for (int i = 25 ; i >= 0 ; -- i) {
        if (a[i] != zero) {
            res += (LL)(x --) * sum[a[i]] % Q;
            res %= Q;
        }
    }
    static int ca = 0;
    printf("Case #%d: %d\n" , ++ ca , res);
}

int main() {
    power[0] = 1;
    for (int i = 1 ; i < N ; ++ i) {
        power[i] = (LL)power[i - 1] * 26 % Q;
    }
    while (~scanf("%d" , &n)) {
        work();
    }
    return 0;
}
