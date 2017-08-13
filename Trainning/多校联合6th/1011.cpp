//TDteam01
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
int N,T;
int a,b,c,ab,bc,ac,abc;
int ans;
int temp,t1,t2,t3,t4,t5,t6;
bool tf;

int main()
{
	//freopen("1011.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		tf = true;
		ans = 0;
		scanf("%d",&N);
		for(int i = 0; i < N;++i)
		{
		scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
			temp = a + b + c - ab - bc - ac + abc;
			if(ab<abc||bc<abc||ac<abc||a<ab||a<ac||b<ab||b<bc||c<ac||c<bc)
				continue;
			t1 = a - ab - ac + abc;
			t2 = b - ab - bc + abc;
			t3 = c - bc - ac + abc;
			if(t1<0||t2<0||t3<0)
				continue;
			if(temp>ans)
				ans = temp;
		}
		printf("%d\n",ans);

	}
}