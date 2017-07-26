#include <stdio.h>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxm = 11, maxn = 100001, maxLen = 18, maxs = 1 << maxLen, mod = 985661441, gen = 3;
inline int mod_pow(int x, int k)
{
	int ret = 1;
	for( ; k; k >>= 1, x = (int)((LL)x * x % mod))
		if(k & 1)
			ret = (int)((LL)ret * x % mod);
	return ret;
}
int inv2[maxLen + 1], w[maxs];
inline int mod_add(int x, int y)
{
	return x + y >= mod ? x + y - mod : x + y;
}
inline int mod_sub(int x, int y)
{
	return x - y < 0 ? x - y + mod : x - y;
}
inline void NTT(int len, int x[], bool flag)
{
	for(int i = 0, j = 0; i < len; ++i)
	{
		if(i > j)
			std::swap(x[i], x[j]);
		for(int l = len >> 1; (j ^= l) < l; l >>= 1);
	}
	for(int i = 1, d = 1; d < len; ++i, d <<= 1)
		for(int j = 0; j < len; j += d << 1)
			for(int k = 0; k < d; ++k)
			{
				int t = (LL)w[(maxs >> i) * k] * x[j + k + d] % mod;
				x[j + d + k] = mod_sub(x[j + k], t);
				x[j + k] = mod_add(x[j + k], t);
			}
	if(flag)
	{
		std::reverse(x + 1, x + len);
		int bitLen = 0;
		for( ; 1 << bitLen < len; ++bitLen);
		int val = inv2[bitLen];
		for(int i = 0; i < len; ++i)
			x[i] = (LL)x[i] * val % mod;
	}
}
int fact[maxn << 1], iact[maxn];
int n, m, k, e[maxm], h[2][maxm], cur, pre = 1, ans[maxm];
int f[maxs], g[maxs];
int main()
{
	w[0] = 1;
	w[1] = mod_pow(gen, (mod - 1) >> maxLen);
	for(int i = 2; i < maxs; ++i)
		w[i] = (LL)w[i - 1] * w[1] % mod;
	inv2[0] = 1;
	inv2[1] = (mod + 1) >> 1;
	for(int i = 2; i <= maxLen; ++i)
		inv2[i] = (LL)inv2[i - 1] * inv2[1] % mod;
	fact[0] = 1;
	for(int i = 1; i < maxn << 1; ++i)
		fact[i] = (LL)fact[i - 1] * i % mod;
	iact[1] = 1;
	for(int i = 2; i < maxn; ++i)
		iact[i] = mod - (int)(mod / i * (LL)iact[mod % i] % mod);
	iact[0] = 1;
	for(int i = 1; i < maxn; ++i)
		iact[i] = (LL)iact[i - 1] * iact[i] % mod;
	for(int Case = 1; scanf("%d%d", &m, &k) == 2; ++Case)
	{
		n = 0;
		for(int i = 0; i < m; ++i)
		{
			scanf("%*d%d", e + i);
			n += e[i];
		}
		int len;
		for(len = 1; len < (n + 1) << 1; len <<= 1);
		f[0] = 0;
		int delta = 1;
		for(int i = 0; i < m; ++i)
			delta = (LL)delta * iact[e[i]] % mod;
		for(int i = 1; i <= n; ++i)
		{
			f[i] = (LL)delta * iact[i] % mod * mod_pow(iact[i - 1], m) % mod;
			for(int j = 0; j < m; ++j)
				f[i] = (LL)f[i] * fact[e[j] + i - 1] % mod;
		}
		memset(f + n + 1, 0, (len - n - 1) * sizeof(int));
		NTT(len, f, 0);
		for(int i = 0; i <= n; ++i)
			g[i] = i & 1 ? mod - iact[i] : iact[i];
		memset(g + n + 1, 0, (len - n - 1) * sizeof(int));
		NTT(len, g, 0);
		for(int i = 0; i < len; ++i)
			f[i] = (LL)f[i] * g[i] % mod;
		NTT(len, f, 1);
		memset(ans + 1, 0, k * sizeof(int));
		for(int i = 1; i <= n; ++i)
		{
			cur ^= 1;
			pre ^= 1;
			f[i] = (LL)f[i] * fact[i] % mod;
			h[cur][0] = 1;
			for(int j = 1; j <= k; ++j)
				h[cur][j] = (LL)h[cur][j - 1] * f[i] % mod;
			if(i > 1)
				for(int j = 1; j <= k; ++j)
					ans[j] = (ans[j] + (LL)h[cur][j - 1] * h[pre][k - j + 1]) % mod;
		}
		if((ans[1] += h[cur][k]) >= mod)
			ans[1] -= mod;
		printf("Case #%d:", Case);
		for(int i = 1; i <= k; ++i)
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}
