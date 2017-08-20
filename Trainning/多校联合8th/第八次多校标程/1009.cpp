#include <vector>
#include <cassert>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long llint;

struct Edge {
  int x, y, w;
};

bool operator < (const Edge &a, const Edge &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int dmst(int N, vector <Edge> &E, int root) {
  const int inf = -1e9;
  vector<int> cost(N), back(N), label(N), bio(N);
  int ret = 0;
  while (1) {
    REP(i, N) cost[i] = inf;
    for (auto e:  E) {
      if (e.x == e.y) continue;
      if (e.w > cost[e.y]) cost[e.y] = e.w, back[e.y] = e.x;
    }
    cost[root] = 0;
    REP(i, N) if (cost[i] == inf) return -1;
    REP(i, N) ret += cost[i];
    int K = 0;
    REP(i, N) label[i] = -1;
    REP(i, N) bio[i] = -1;
    REP(i, N) {
      int x = i;
      for (; x != root && bio[x] == -1; x = back[x])
        bio[x] = i;
      if (x != root && bio[x] == i) {
        for (; label[x] == -1; x = back[x])
          label[x] = K;
        ++K;
      }
    }
    if (K == 0) break;
    REP(i, N) if (label[i] == -1)
      label[i] = K++;

    for (auto & e:  E) {
      int xx = label[e.x];
      int yy = label[e.y];
      if (xx != yy)
        e.w -= cost[e.y];
      e.x = xx;
      e.y = yy;
    }
    root = label[root];
    N = K;
  }
  return ret;
}

void check_connectivity(int N, vector<Edge> &E) {
  vector<bool> vis(N);
  vis[0] = true;
  REP(i, N) {
    for (auto e: E) {
      if (vis[e.x]) vis[e.y] = true;
    }
  }
  REP(i, N) {
    assert(vis[i]);
  }
}

void check_dup(vector<Edge> &E) {
  sort(E.begin(), E.end());
  REP(i, E.size() - 1) {
    Edge &a = E[i];
    Edge &b = E[i + 1];
    assert(a.x != b.x || a.y != b.y);
  }
}

int main() {
  int tn, n, m;
  scanf("%d", &tn);
  REP(ti, tn) {
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 1000 && 1 <= m && m <= 10000);
    vector<Edge> edges;
    REP(i, m) {
      Edge e;
      scanf("%d%d%d", &e.x, &e.y, &e.w);
      assert(1 <= e.x && e.x <= n);
      assert(1 <= e.y && e.y <= n);
      assert(1 <= e.w && e.w <= 100);
      assert(e.y != 1);
      e.x -= 1; e.y -= 1;
      e.w *= n;
      if (e.y == n - 1) {
        e.w += (n - 1 - e.x);
      }
      edges.push_back(e);
    }
    check_connectivity(n, edges);
    check_dup(edges);
    int ans = dmst(n, edges, 0);
    int cost = ans / n;
    int idx = n - 1 - (ans % n);
    printf("%d %d\n", cost, idx + 1);
  }
  return 0;
}
