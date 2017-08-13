#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))

int main(){
	int n, ca; ll k;
	while(~scanf("%d%lld", &n, &k)){
		if(k <= n) printf("Case #%d: %lld\n", ++ca, k);
		else{
			k -= n;
			ll t = k / (n - 1);
			k %= n - 1;
			if(!k) printf("Case #%d: %d\n", ++ca, t & 1 ? n - 1 : n);
			else printf("Case #%d: %lld\n", ++ca, k);
		}
	}
  return 0;
}
