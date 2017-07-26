#include <cmath>
#include <stdio.h>
int solve(int m)
{
	int ret = (int)floor(m * log10((long double)2));
	return ret;
}
int main()
{
	for(int Case = 1, m; scanf("%d", &m) == 1; ++Case)
		printf("Case #%d: %d\n", Case, solve(m));
	return 0;
}
