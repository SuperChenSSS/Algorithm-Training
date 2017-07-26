#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
namespace fastIO {
	#define BUF_SIZE 100000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(int &x) {
		char ch;
		while(blank(ch = nc()));
		if(IOerror)
			return;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
	#undef BUF_SIZE
};
using namespace fastIO;
const int maxn = 1000001, mod = 1000000007;
int fact[maxn], iact[maxn];
int n, l[maxn], r[maxn], ord[maxn], pL[maxn], pR[maxn], sz[maxn], tmp[maxn];
int bfs(int rt)
{
	int L = 0, R = 0;
	static int que[maxn], f[maxn];
	que[R++] = rt;
	while(L < R)
	{
		int u = que[L++], vL = pL[u], vR = pR[u];
		// [L, R] at x -> [L, x-1] [x+1, R]
		if(l[u] == u)
		{
			if(vL != -1)
				return 0;
		}
		else
		{
			if(vL == -1 || vL >= u || r[vL] != u - 1)
				return 0;
			que[R++] = vL;
		}
		if(u == r[u])
		{
			if(vR != -1)
				return 0;
		}
		else
		{
			if(vR == -1 || vR <= u || l[vR] != u + 1)
				return 0;
			que[R++] = vR;
		}
	}
	for(int i = n - 1; i >= 0; --i)
	{
		int u = que[i], ret = 1, szL, szR;
		if(l[u] == u)
			szL = 0;
		else
		{
			ret = (LL)ret * f[pL[u]] % mod;
			szL = sz[pL[u]];
		}
		if(u == r[u])
			szR = 0;
		else
		{
			ret = (LL)ret * f[pR[u]] % mod;
			szR = sz[pR[u]];
		}
		if(szL && szR)
			ret = (LL)ret * fact[szL + szR] % mod * iact[szL] % mod * iact[szR] % mod;
		sz[u] = szL + szR + 1;
		f[u] = ret;
	}
	return f[rt];
}
int main()
{
	iact[1] = 1;
	for(int i = 2; i < maxn; ++i)
		iact[i] = mod - (int)(mod / i * (LL)iact[mod % i] % mod);
	fact[0] = iact[0] = 1;
	for(int i = 1; i < maxn; ++i)
	{
		fact[i] = (LL)fact[i - 1] * i % mod;
		iact[i] = (LL)iact[i - 1] * iact[i] % mod;
	}
	for(int Case = 1; read(n), !fastIO::IOerror; ++Case)
	{
		for(int i = 1; i <= n; ++i)
			read(l[i]);
		for(int i = 1; i <= n; ++i)
			read(r[i]);
		ord[0] = ord[n + 1] = 0;
		int *cnt = sz;
		memset(cnt + 1, 0, n * sizeof(int));
		for(int i = 1; i <= n; ++i)
			++cnt[r[i]];
		for(int i = 2; i <= n; ++i)
			cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; --i)
			tmp[cnt[r[i]]--] = i;
		memset(cnt + 1, 0, n * sizeof(int));
		for(int i = 1; i <= n; ++i)
			++cnt[l[i]];
		for(int i = 2; i <= n; ++i)
			cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; --i)
			ord[cnt[l[tmp[i]]]--] = tmp[i];
		for(int i = 1; i <= n; ++i)
			pL[ord[i]] = l[ord[i - 1]] == l[ord[i]] ? ord[i - 1] : -1;
		memset(cnt + 1, 0, n * sizeof(int));
		for(int i = 1; i <= n; ++i)
			++cnt[l[i]];
		for(int i = 2; i <= n; ++i)
			cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; --i)
			tmp[cnt[l[i]]--] = i;
		memset(cnt + 1, 0, n * sizeof(int));
		for(int i = 1; i <= n; ++i)
			++cnt[r[i]];
		for(int i = 2; i <= n; ++i)
			cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; --i)
			ord[cnt[r[tmp[i]]]--] = tmp[i];
		for(int i = 1; i <= n; ++i)
			pR[ord[i]] = r[ord[i]] == r[ord[i + 1]] ? ord[i + 1] : -1;
		int pos = -1;
		for(int i = 1; i <= n; ++i)
			if(l[i] == 1 && r[i] == n)
			{
				pos = i;
				break;
			}
		printf("Case #%d: %d\n", Case, pos == -1 ? 0 : bfs(pos));
	}
	return 0;
}
