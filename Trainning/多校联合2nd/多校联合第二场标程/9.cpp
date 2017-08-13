#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

int n , a[maxn] , mx , T , ans = 0 , sum[maxn] , f[maxn] , cas = 0;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

inline int mul( int x , int y ){
	return 1LL * x * y % mod;
}

inline void upd( int & x , int y ){
	x += y;
	if( x >= mod )
		x -= mod;
}

int power( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 )
			ret = mul( ret , x );
		y >>= 1;
		x = mul( x , x );
	}
	return ret;
}

int main( int argc , char * argv[] ){
	//freopen( "data.in" , "r" , stdin );
	//freopen( "data.out" , "w" , stdout );
	scanf( "%d" , & T );
	while( T -- ){
		scanf( "%d" , & n );
		mx = 0;
		memset( f , 0 , sizeof( f ) );
		memset( sum , 0 , sizeof( sum ) );
		for(int i = 1 ; i <= n ; ++ i){
			scanf( "%d" , a + i );
			++ sum[a[i]];
			mx = max( mx , a[i] );
		}
		for(int i = 1 ; i <= mx ; ++ i) sum[i] += sum[i - 1];
		for(int i = 2 ; i <= mx ; ++ i){
			f[i] = 1;
			if( sum[i - 1] ){
				f[i] = 0;
				continue;
			}
			int rx = 0;
			for(int j = i ; j <= mx ; j += i){
				int k = min( mx , j + i - 1 ) , x = sum[k] - sum[j - 1];
				rx += x;
				f[i] = mul( f[i] , power( j / i , x ) );
			}
			if( rx != n )
				f[i] = 0;
		}
		for(int i = mx ; i >= 2 ; -- i)
			for(int j = i + i ; j <= mx ; j += i)
				upd( f[i] , mod - f[j] );
		int ans = 0;
		for(int i = 2 ; i <= mx ; ++ i)
			upd( ans , f[i] );
		printf( "Case #%d: %d\n" , ++ cas , ans );
	}
	//cerr << "run time is " << clock() << endl;
	return 0;
}
