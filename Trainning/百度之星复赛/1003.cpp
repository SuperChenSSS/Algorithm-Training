#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue> 
typedef long long ll;
using namespace std;
const int maxn = 1e4 + 5;
const ll mod = 1e9 + 7;
ll f[maxn],g[maxn];

int main(){
	f[1] = 2;
	f[0] = 1;
	for(int i = 2;i < maxn;i++){
		f[i] = 2 * f[i - 1] % mod;
	}
	g[1] = 0;
	g[0] = 0;
	for(int i = 2;i < maxn;i++){
		g[i] = (4 * (f[i - 2] + g[i - 2]) + 2 * (f[i - 1] + g[i - 1])) % mod;
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans = 0;

		for(int i = 1;i <= n;i++){
			if(i == 1 || i == n){
			   ans = (ans + f[n] + g[n]) % mod;
			}else{
			   	ans = (ans + f[i] * (f[n - i] + g[n - i]) % mod) % mod;
				ans = (ans + f[n - i + 1] * (f[i - 1] + g[i - 1]) % mod) % mod;
			}
		}
		cout << ans << endl;
	}


	return 0;
}