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

const int maxn = 1e5 + 10;

int n, unique_n;
int w[maxn], value_list[maxn], id[maxn], size[maxn];
int left_son[maxn], right_son[maxn];
long long cnt_num[maxn], cnt_sum[maxn];
vector<int> e[maxn];

int get_size(int u, int pre) {
    size[u] = 1;
    for (int i = 0; i < e[u].size(); i++) 
        if (e[u][i] != pre) {
            if (left_son[u] == -1) left_son[u] = e[u][i];
            else right_son[u] = e[u][i];
            size[u] += get_size(e[u][i], u);
        }
    if (~left_son[u] && ~right_son[u] && size[ left_son[u] ] > size[ right_son[u] ])
        swap(left_son[u], right_son[u]);
    return size[u];
}

long long query(long long *r, int x) {
    long long rt = 0;
    while (x) {
        rt += r[x];
        x -= x & -x;
    }
    return rt;
}

void update(long long *r, int x, int value) {
    if (x == 0) return ;
    while (x <= unique_n) {
        r[x] += value;
        x += x & -x;
    }
}

long long current_answer;
long long f[maxn];

void add_number(int inx) {
    current_answer += (query(cnt_num, unique_n) - query(cnt_num, inx)) * value_list[inx] + value_list[inx];
    current_answer += query(cnt_sum, inx);
    update(cnt_num, inx, 1);
    update(cnt_sum, inx, value_list[inx]);
    //cout << '+' << w[inx] << endl;
    //cout << current_answer << endl;
}

void del_number(int inx) {
    update(cnt_num, inx, -1);
    update(cnt_sum, inx, -value_list[inx]);
    current_answer -= (query(cnt_num, unique_n) - query(cnt_num, inx)) * value_list[inx] + value_list[inx];
    current_answer -= query(cnt_sum, inx);
}

void clean(int u) {
    del_number(id[u]);
    if (~left_son[u]) clean(left_son[u]);
    if (~right_son[u]) clean(right_son[u]);
}

void validate(int u) {
    add_number(id[u]);
    if (~left_son[u]) validate(left_son[u]);
    if (~right_son[u]) validate(right_son[u]);
}

void get_ans(int u) {
    if (!~left_son[u]) {
        f[u] = w[u];
        add_number(id[u]);
        return ;
    }

    
    get_ans(left_son[u]);

    if (~right_son[u]) {
        clean(left_son[u]);
        get_ans(right_son[u]);
        validate(left_son[u]);
        add_number(id[u]);
        f[u] = current_answer;
    }
    else {
        add_number(id[u]);
        f[u] = current_answer;
    }
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;

    while (cases--) {
        cin >> n;
        assert(100000);
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            value_list[i] = w[i];
            assert(w[i] <= 100000000 && 1 <= w[i]);
        }
        sort(value_list + 1, value_list + n + 1);
        unique_n = unique(value_list + 1, value_list + n + 1) - value_list - 1;

        current_answer = 0;
        for (int i = 1; i <= unique_n; i++) 
            cnt_num[i] = cnt_sum[i] = 0;

        for (int i = 1; i <= n; i++) {
            id[i] = lower_bound(value_list + 1, value_list + unique_n, w[i]) - value_list;
            left_son[i] = right_son[i] = -1;
        }

        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            e[u].push_back(v); e[v].push_back(u);
        }

        get_size(1, 0);
        get_ans(1);
        for (int i = 1; i <= n; i++) cout << f[i] << ' ';
        cout << endl;
    }
    return 0;
}
