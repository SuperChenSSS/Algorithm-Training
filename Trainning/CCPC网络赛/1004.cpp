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
using std::cin;
using std::cout; 
using std::ios; 
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
char arr1[maxn];
char arr2[maxn];
char tmp[maxn];
void kmp_pre(char x[],int m,int next[])
{
	int i,j;
	j = next[0] = -1;
	i = 0;
	while (i<m) {
		while(j!=-1 && x[i]!=x[j])
			j = next[j];
		next[++i] = ++j;
	}
}
/*
	kmpNext[]的意思：next[i] = next[next[...[next[i]]]](直到next[i]<0或者x[next'[i]]!=x[i])
	这样的预处理可以快一些
*/
void preKMP(char x[],int m,int kmpNext[])
{
	int i,j;
	j = kmpNext[0] = -1;
	i = 0;
	while(i<m)
	{
		while(j!=-1 && x[i]!=x[j])
			j = kmpNext[j];
		if(x[++i] == x[++j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
	}	
}
//返回x在y中出现的次数，可以重叠
int next[100010];
int KMP_Count(char x[],int m,char y[],int n)
{//x是模式串，y是主串
	int i,j;
	int ans = 0;
	//preKMP(x,m,next);
	kmp_pre(x,m,next);
	i = j = 0;
	while(i<n)
	{
		while(j!=-1 && y[i]!=x[j])
			j = next[j];
		i++;j++;
		if(j>=m)
		{
			ans++;
			j = next[j];
		}
	}		
	return ans;
}	

int main()
{
	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		//memset(tmp,0,sizeof(tmp));
		ll answer = 0;
		cin>>arr1;
		cin>>arr2;
		int len = strlen(arr2);
		while(len>0)
		{
			for(int i=0;i<len;i++)
				tmp[i] = arr2[i];
			answer += KMP_Count(tmp,strlen(tmp),arr1,strlen(arr1)) * len;
			len--;
		}
		cout<<(answer+1)%mod<<"\n";
	}
	return 0;
}