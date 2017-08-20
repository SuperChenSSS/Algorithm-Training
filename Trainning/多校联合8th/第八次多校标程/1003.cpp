#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
const double eps = 1e-7;
const double inf = 1e20;

struct AntType {
    int dis, vel, id, inx;
    double dst;
    bool operator < (const AntType &b) const {
        return this->dis < b.dis;
    }
};

int n, L;
int last;
AntType ant[maxn];
AntType *list[maxn], *tmp[maxn];
bool vis[maxn];

void work(int x, int y) {
    if (x == y) return ;
    int mid = (x + y) >> 1;
    work(x, mid);
    work(mid + 1, y);

    int i = x, j = mid + 1, p = x;
    double leftBest = -inf, leftLeast = inf, rightBest = -inf, rightLeast = inf;
    double acLeftBest = -inf, acLeftLeast = inf, acRightBest = -inf, acRightLeast = inf;

    while (i <= mid || j <= y) {
        if (j == y + 1 || (i != mid + 1 && list[i]->id > list[j]->id)) {
            //if (x == 0 && y == 4) {
                //cout << "i: " << i << ' ' << list[i]->inx << endl;
            //}
            // put list[i]
            if (p != x && list[i]->id != tmp[p - 1]->id) {
                acLeftBest = leftBest;
                acLeftLeast = leftLeast;
                acRightBest = rightBest;
                acRightLeast = rightLeast;
            }

            if (acRightLeast <= list[i]->dst || acRightBest >= list[i]->dst + L) vis[ list[i]->inx ] = true;
            tmp[p++] = list[i];
            leftBest = max(leftBest, list[i]->dst);
            leftLeast = min(leftLeast, list[i]->dst);
            i++;
        }
        else {
            // put list[j]
            //if (x == 0 && y == 4) {
                //cout << "j: " << j << ' ' << list[j]->inx << endl;
            //}
            if (p != x && list[j]->id != tmp[p - 1]->id) {
                acLeftBest = leftBest;
                acLeftLeast = leftLeast;
                acRightBest = rightBest;
                acRightLeast = rightLeast;
            }
            if (acLeftLeast <= list[j]->dst - L || acLeftBest >= list[j]->dst) vis[ list[j]->inx ] = true;
            tmp[p++] = list[j];
            rightBest = max(rightBest, list[j]->dst);
            rightLeast = min(rightLeast, list[j]->dst);
            j++;
        }
    }
    //cout << x << ' ' << y << endl;
    //for (int i = x; i <= y; i++) 
        //cout << tmp[i]->inx << ' ' << tmp[i]->id << ' ' << tmp[i]->dis << ' ' << tmp[i]->dst << ' ' << vis[ tmp[i]->inx ] << endl;
    for (int i = x; i <= y; i++) list[i] = tmp[i];
}

int highestId;
bool ok(double t) {
    for (int i = 0; i < n; i++) 
        vis[i] = false, list[i] = &ant[i], ant[i].dst = t * ant[i].vel + ant[i].dis;
    work(0, n - 1);
    for (int i = 0; i < n; i++) 
        if (ant[i].id != highestId && !vis[i]) {/*cout << i << ' ' << ant[i].id << ' ' << ant[i].inx << ' ' << endl;*/ last = i; return false;}
    return true;
}

void update(int &up, int &down, const AntType &a, const AntType &b) {
    if (a.vel < b.vel) {update(up, down, b, a); return ;}
    int cur_up, cur_down;
    if (a.dis < b.dis) {
        cur_up = b.dis - a.dis;
        cur_down = a.vel - b.vel;
    }
    else {
        cur_up = L + b.dis - a.dis;
        cur_down = a.vel - b.vel;
    }
    //cout << up << ' ' << down << endl;
    //cout << cur_up << ' ' << cur_down << endl;

    //if (cur_up % cur_down == 0 && cur_up / cur_down == 4) {
        //cout << L << endl;
        //cout << a.id << ' ' << a.id << ' ' << a.dis << ' ' << a.vel << endl;
        //cout << b.id << ' ' << b.id << ' ' << b.dis << ' ' << b.vel << endl;
    //}

    if ((up == 0 && down == 0) || 1LL * cur_up * down < 1LL * cur_down * up) {
        up = cur_up;
        down = cur_down;
    }
}

double calc(const AntType &a, const AntType &b) {
    if (a.vel < b.vel) return calc(b, a);
    if (a.dis < b.dis) return 1.0 * (b.dis - a.dis) / (a.vel - b.vel);
    return 1.0 * (L + b.dis - a.dis) / (a.vel - b.vel);
}

int main(int argc, char **argv) {
    int cases;
    scanf("%d", &cases);
    for (int T = 1; T <= cases; T++) {
        scanf("%d%d", &n, &L);
        assert(1 <= n && n <= 100000);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ant[i].dis);
            assert(1 <= ant[i].dis && ant[i].dis < L);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &ant[i].vel);
            assert(-1000000 <= ant[i].vel <= 1000000);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &ant[i].id);
            assert(0 <= ant[i].id && ant[i].id <= n);
        }
        
        highestId = -2147483647;
        for (int i = 0; i < n; i++) highestId = max(highestId, ant[i].id);

        sort(ant, ant + n);
        for (int i = 0; i < n; i++) ant[i].inx = i;

        int root;
        for (int i = 0; i < n; i++) 
            if (ant[i].id == highestId) root = i;

        double i = 0, j = 0, mid;

        for (int i = 0; i < n; i++) 
            if (i != root) j = max(calc(ant[i], ant[root]), j);

        last = -1;
        while (i < j - eps) {
            mid = (i + j) / 2;
            if (ok(mid)) j = mid;
            else i = mid;
        }

        if (last == -1) {
            printf("0\n");
            continue;
        }

        int up = 0, down = 0;

        //cout << ant[last].id << ' ' << ant[last].dis << ' ' << ant[last].vel << endl;

        for (int i = 0; i < n; i++) 
            if (ant[i].id > ant[last].id) update(up, down, ant[i], ant[last]);
        //cout << up << ' ' << down << endl;
        if (up == 0) printf("0\n");
        else {
            int g = __gcd(up, down);
            printf("%d/%d\n", up / g, down / g);
        }
    }
    return 0;
}
