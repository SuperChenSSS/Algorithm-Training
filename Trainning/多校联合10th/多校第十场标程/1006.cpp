#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7, N = 5e6+7, M = 105;
vector<ll> vec, val;
ll pw, dp[N];
int flg, A[M][M], B[M][M], C[M][M];

ll modExp(ll p) {
	if (!p) return 1;
	ll t = modExp(p>>1);
	return t*t*((p%2)+1)%MOD;
}

void mul(int A[M][M], int B[M][M], int p) {
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			ll cur = 0;
			for (int k = 0; k < p; k++) cur += 1LL*A[i][k]*B[k][j]%MOD;
			C[i][j] = cur%MOD;
		}
	}
	for (int i = 0; i < p; i++) for (int j = 0; j < p; j++) A[i][j] = C[i][j];
}

void matExp(int A[M][M], ll n, int p) {
	memset(B, 0, sizeof B);
	for (int i = 0; i < p; i++) B[i][i] = 1;
	for (; n; n >>= 1, mul(A, A, p)) if (n%2) mul(B, A, p);
	for (int i = 0; i < p; i++) for (int j = 0; j < p; j++) A[i][j] = B[i][j];
}

ll sol1(int x) {
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		dp[i] = 0;
		for (int j = 0; j < vec.size(); j++) if (vec[j] <= i) dp[i] = (dp[i]+dp[i-vec[j]]*val[j])%MOD;
		if (flg && 4 <= i) dp[i] = (dp[i]+dp[i-4]*4)%MOD;
	}
	return dp[x];
}

ll sol2(int x) {
	int p = vec.back();
	if (flg && p < 4) p = 4;
	sol1(p);
	if (x <= p) return dp[x];
	memset(A, 0, sizeof A);
	for (int i = 0; i < vec.size(); i++) A[0][vec[i]-1] = val[i];
	if (flg) A[0][3] += 4;
	for (int i = 1; i < p; i++) A[i][i-1] = 1;
	matExp(A, x-p+1, p);
	ll ret = 0;
	for (int i = 0; i < p; i++) ret += A[0][i]*dp[p-i-1]%MOD;
	return ret%MOD;
}

int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		ll n, k; scanf("%lld%lld", &n, &k);
		ll t = k;
		pw = 1;
		while (!(t&1)) t /= 2, pw *= 2;
		flg = (pw == 2) ? 1:0;
		vec.clear();
		for (ll i = 1; i*i <= t; i++) {
			if (t % i == 0) {
				vec.push_back(i*pw);
				if (i*i < t) vec.push_back(t/i*pw);
			}
		}
		sort(vec.begin(), vec.end());
		val.clear();
		for (int i = 0; i < vec.size(); i++) val.push_back(vec[i] <= 2 ? vec[i]:modExp(vec[i]));
		printf("%lld\n", k < 60 ? sol2(n):sol1(n));
	}
}

