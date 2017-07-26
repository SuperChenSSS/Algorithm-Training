#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n , m , K;

struct opt {
    int w , x , y;
    bool operator < (const opt& R) const {
        return w < R.w;
    }
};

vector<int> W;
void merge(vector<int> &V , vector<int> B) {
    priority_queue< opt > Q;
    for (int i = 0 ; i < B.size() ; ++ i) {
        Q.push((opt) {V[0] + B[i] , i , 0});
    }
    W.resize(0);
    while (W.size() < K && !Q.empty()) {
        auto it = Q.top(); Q.pop();
        W.push_back(it.w);
        if (it.y + 1 < V.size()) {
            ++ it.y;
            Q.push((opt) {B[it.x] + V[it.y] , it.x , it.y});
        }
    }
    V = W;
}

int pre[N] , mcnt;
struct edge {
    int x , w , next;
} e[N << 2];

vector<int> res;

int dfn[N] , low[N] , ncnt;
stack<int> S;

void dfs(int x , int fa) {
    dfn[x] = low[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!dfn[y]) {
            S.push(i);
            dfs(y , i ^ 1);
            low[x] = min(low[x] , low[y]);
            if (low[y] > dfn[x]) {}//(x , y) is bridge
            if (low[y] >= dfn[x]) {
                int j;
                vector<int> V;
                do {
                    j = S.top();
                    S.pop();
                    V.push_back(e[j].w);
                } while (j != i);
                if (V.size() > 1) {
                    //cout << V.size() << endl;
                    //for (auto &x : V) cout << x << ' '; cout << endl;
                    merge(res , V);
                }
            }
        } else if (i != fa && dfn[y] < dfn[x])
            S.push(i) , low[x] = min(low[x] , dfn[y]);
    }
}

void work() {
    memset(pre , -1 , sizeof(pre));
    mcnt = ncnt = 0;
    int sum = 0;
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
        sum += z;
    }
    scanf("%d" , &K);
    res.resize(0);
    res.push_back(0);
    memset(dfn , 0 , sizeof(dfn));
    dfs(1 , 0);
    int w = 0;
    for (int i = 0 ; i < res.size() ; ++ i) {
        w += (i + 1) * (sum - res[i]);
    }
    static int ca = 0;
    printf("Case #%d: %u\n" , ++ ca , w);
}

int main() {
	res.reserve(100001);
	W.reserve(100001);
    while (~scanf("%d%d" , &n , &m)) {
        work();
    }
    return 0;
}
