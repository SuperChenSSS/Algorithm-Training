#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int maxn = 1e6;
using namespace std;
int main() {
	int n,L[maxn];
	while (cin>>n) {
		for(int i=0;i<n;i++)
			cin>>L[i];
		ll ans = 0;
		//直到计算到木板为1块时为止
		while(n>1)
		{//求出最短的板mii1和次短的板mii2
			int mii1 = 0,mii2 = 1;
			if(L[mii1] > L[mii2]) swap(mii1,mii2);
			for(int i=2;i<n;i++)
				if(L[i] < L[mii1])//选取最短的板
				{
					mii2 = mii1;
					mii1 = i;
				}
				else if(L[i] < L[mii2])//选取次短的板
				{
					mii2 = i;
				}
			//将两块板拼合
			int t = L[mii1] + L[mii2];
			ans += t;
			
			if(mii1 == n - 1) swap(mii1,mii2);
			L[mii1] = t;
			L[mii2] = L[n-1];
			n--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}