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
const int maxn = 1e6;
const int mod = (1e9+7); 

int n,m,k,base[105];
char st[1005];
ll state[105][10][2];

ll dfs(int pos,int nb,int type,int z,int k)
{
	if(pos<0) 
		return z;
	if(z && k && state[pos][nb][type]!=-1)
		return state[pos][nb][type];
	ll result = 0;
	int number = 9;
	if(k==0) 
		number = base[pos];
	for(int i=0;i<=number;i++){
		if((i<nb) && type)
			continue;
		int now=( ((i>nb) && z) || type ? 1:0 );
		result += dfs(pos-1,i,now,z||i,k||i<base[pos]);
		result %= mod;
	}
	if(z && k) 
		state[pos][nb][type] = result;
	return result;
}

int main(){
	memset(state,-1,sizeof state);
	int t; 
	cin>>t;
	getchar();
	while(t--){
		cin>>st;
		int len = strlen(st);
	    for(int i=0;i<len;i++)
	        base[i]=st[i]-'0';
	    reverse(base,base+len);
		ll answer = dfs(len-1,0,0,0,0);
		cout<<answer<<"\n";
	}
	return 0;
}