#include <stdio.h>
#include <cstring>
const int maxn = 50000, mod = 1000000007;
int t, n, m, f[maxn << 1 | 1], ans;
inline void mod_inc(int &x, int y)
{
	if((x += y) >= mod)
		x -= mod;
}
inline void mod_dec(int &x, int y)
{
	if((x -= y) < 0)
		x += mod;
}
int main()
{
	for(int Case = 1; scanf("%d%d", &n, &m) == 2; ++Case)
	{
		f[0] = 1;
		memset(f + 1, 0, (n << 1) * sizeof(int));
		for(int i = 1; i <= (n << 1); ++i)
		{
			for(int j = 1, w = 1; w <= i; w += 3 * j + 1, ++j)
				if(j & 1)
					mod_inc(f[i], f[i - w]);
				else
					mod_dec(f[i], f[i - w]);
			for(int j = 1, w = 2; w <= i; w += 3 * j + 2, ++j)
				if(j & 1)
					mod_inc(f[i], f[i - w]);
				else
					mod_dec(f[i], f[i - w]);
		}
		for(int i = 1, a; i <= n; ++i)
		{
			scanf("%d", &a);
			if((n << 1) < i * (a + 1LL))
				continue;
			for(int j = n << 1, w = i * (a + 1); j >= w; --j)
				mod_dec(f[j], f[j - w]);
		}
		for(int i = 1, s = f[0]; i <= n; mod_inc(s, f[i++]))
			mod_dec(f[n + i], s);
		ans = 0;
		for(int b; m--; )
		{
			scanf("%d", &b);
			mod_inc(ans, f[(n << 1) - b]);
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
