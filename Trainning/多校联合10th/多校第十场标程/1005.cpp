#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<19;
const int M = 998244353;

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

void NTT(int *A, int N, int W, int M) {
	for (int n = N, h = n >> 1; n > 1; n >>= 1, h >>= 1, W = 1LL * W * W % M) {
		for (int i = 0, w = 1; i < h; w = 1LL * w * W % M, i++) {
			for (int j = i, k = i+h; j < N; k += n, j += n) {
				int x = (A[j] - A[k] + M) % M;
				A[j] += A[k], A[j] %= M, A[k] = 1LL * x * w % M;
			}
		}
	}
	for (int i = 0, j = 1; j < N-1; j++) {
		for (int k = N >> 1; (i ^= k) < k; k >>= 1);
		if (i < j) swap(A[i], A[j]);
	}
}

int A0[MAXN], A1[MAXN], B0[MAXN], B1[MAXN], A[MAXN], B[MAXN];

void inverse(int *A, int *B, int N, int Q, int M) {
	vector<int> W, IW;
	int IQ = modExp(Q, M-2, M);
	for (int n = N; n > 1; n >>= 1, Q = 1LL * Q * Q % M) W.push_back(Q);
	for (int n = N; n > 1; n >>= 1, IQ = 1LL * IQ * IQ % M) IW.push_back(IQ);
	B[0] = modExp(A[0], M-2, M);
	for (int n = 2, h = 1, in = (M+1) >> 1; n <= N; h <<= 1, n <<= 1, in = 1LL * in * ((M+1) >> 1) % M) {
		int w = W.back(); W.pop_back();
		int iw = IW.back(); IW.pop_back();
		for (int i = 0; i < n; i++) A0[i] = ((i < h) ? A[i] : 0);
		for (int i = 0; i < n; i++) A1[i] = ((i >= h) ? 1LL * A[i] * in % M : 0);
		for (int i = 0; i < n; i++) B0[i] = ((i < h) ? B[i] : 0);
		NTT(A0, n, w, M);
		NTT(A1, n, w, M);
		NTT(B0, n, w, M);
		for (int i = 0; i < n; i++) B0[i] = 1LL * B0[i] * B0[i] % M;
		for (int i = 0; i < n; i++) A0[i] = 1LL * A0[i] * B0[i] % M;
		NTT(B0, n, iw, M);
		for (int i = h; i < n; i++) B0[i] = 0;
		NTT(B0, n, w, M);
		for (int i = 0; i < n; i++) A1[i] = (A0[i] + 1LL * A1[i] * B0[i]) % M;
		NTT(A1, n, iw, M);
		for (int i = h; i < n; i++) B[i] = 1LL * (M-A1[i]) * in % M;
	}
}

int a[2][MAXN], b[MAXN], ib[MAXN];
int c[MAXN], d[MAXN], e[MAXN];

void preprocess() {
	a[0][0] = b[0] = 1;
	for (int i = 1; i <= 500; i++) {
		for (int j = 0; j <= 100000; j++) a[1][j] = ((j >= i ? M - a[0][j-i] : 0) + a[1][j-i]) % M;
		for (int j = 0; j <= 100000; j++) a[0][j] = a[1][j], b[j] = (b[j] + a[0][j]) % M;
	}
	int w = modExp(3, M>>19, M);
	inverse(b, ib, 1<<17, modExp(3, M>>17, M), M);
	NTT(ib, MAXN, w, M);
	for (int j = 1; j <= 100000; j++) {
		for (int i = j; i <= 100000; i += j) c[i]++, d[i] += 3 * j, e[i] = (e[i] + 1LL * j * j) % M;
	}
	NTT(c, MAXN, w, M);
	NTT(d, MAXN, w, M);
	NTT(e, MAXN, w, M);
	for (int i = 0, I = modExp(1<<19, M-2, M); i < 1<<19; i++) c[i] = ((1LL * c[i] * c[i] + d[i]) % M * c[i] + e[i]) % M * ib[i] % M * I % M;
	NTT(c, MAXN, modExp(w, M-2, M), M);
}

int main() {
	int ncase, n;
	preprocess();
	for (scanf("%d", &ncase); ncase--; ) scanf("%d", &n), printf("%d\n", c[n]);
	return 0;
}

