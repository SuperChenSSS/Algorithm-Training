#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MOD = 1000000007;

struct Mat {
	LL a[2][2];
	Mat () {
		a[0][0] = a[1][1] = 1;
		a[0][1] = a[1][0] = 0;
	}
} C;
Mat operator * ( const Mat&a, const Mat& b ) {
	Mat ret;
	ret.a[0][0] = ( a.a[0][0] * b.a[0][0] + a.a[0][1] * b.a[1][0] ) % MOD;
	ret.a[0][1] = ( a.a[0][0] * b.a[0][1] + a.a[0][1] * b.a[1][1] ) % MOD;
	ret.a[1][0] = ( a.a[1][0] * b.a[0][0] + a.a[1][1] * b.a[1][0] ) % MOD;
	ret.a[1][1] = ( a.a[1][0] * b.a[0][1] + a.a[1][1] * b.a[1][1] ) % MOD;
	return ret;
}

Mat modExp( Mat a, LL n ) {
	Mat ret;
	for( ; n; n >>= 1, a = a * a )	if( n & 1 )	ret = ret * a;
	return ret;
}

LL get( LL n ) {
	if( n == 0 )	return 0;
	if( n == 1 )	return 1;
	Mat t = modExp(C, n-1);
	return t.a[0][0];
}

LL solve( LL n ) {
	LL a = get(n+1) - 2 * get(n);
	a = (a % MOD + MOD) % MOD;
	return a;
}

int main() {
	freopen("array.in", "r", stdin );
	freopen("array.out", "w", stdout );
	LL n;
	int tcase;
	scanf("%d", &tcase );
	C.a[0][0] = 7,	C.a[0][1] = -4;
	C.a[1][0] = 1,	C.a[1][1] = 0;
	while( tcase-- ) {
		scanf("%lld", &n );
		printf("%lld\n", solve(n) );
	}
	return 0;
}
