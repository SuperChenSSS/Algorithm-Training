//TDteam01
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
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e5;
const int mod = (1e9+7); 
int arr[maxn];
bool judge(int product)
{
	int tmp1,tmp2;
	
	while(product/10)
	{
		tmp1 = product % 10;
		tmp2 = product / 10 % 10;
		if(tmp1-tmp2!=1)
			return false;
		product /= 10;
	}
	return true;
}
int main()
{
	freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	//cout<<judge(135)<<"\n";
	while(cin>>n)
	{
		int num = 0;
		bool flag = false;
		int result[maxn] = {0};
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
		{
			int cheng = arr[i] * arr[j];
			if(judge(cheng)){
				result[num++] = cheng;
				flag = true;
			}
		}
		sort(result,result+num);
		if(!flag)
			cout<<"-1\n";
		else
			cout<<result[num-1]<<"\n";
	}
	return 0;
}