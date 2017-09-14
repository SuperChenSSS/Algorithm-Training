#include<cstdio>    
#include<cstring>    
#include<cstdlib>    
#include<cmath>    
#include<iostream>    
#include<algorithm>    
#include<vector>    
#include<map>    
#include<set>    
#include<queue>    
#include<string>    
#include<bitset>    
#include<utility>    
#include<functional>    
#include<iomanip>    
#include<sstream>    
#include<ctime>   
typedef long long ll; 
using namespace std;  
  
#define MAXN 2  
#define mod 998244353 
ll Fi(ll n);   
struct Matrix  
{  
	ll mat[MAXN][MAXN];  
	Matrix() {}  
	Matrix operator*(Matrix const &b)const  
	{  
		Matrix res;  
		memset(res.mat, 0, sizeof(res.mat));  
		for (int i = 0 ;i < MAXN; i++)  
			for (int j = 0; j < MAXN; j++)  
				for (int k = 0; k < MAXN; k++)  
					res.mat[i][j] = (res.mat[i][j]+this->mat[i][k] * b.mat[k][j])%mod;  
		return res;  
	}  
};  
Matrix pow_mod(Matrix base, int n)  
{  
	Matrix res;  
	memset(res.mat, 0, sizeof(res.mat));  
	for (int i = 0; i < MAXN; i++)  
		res.mat[i][i] = 1;  
	while (n > 0)  
	{  
		if (n & 1) res = res*base;  
		base = base*base;  
		n >>= 1;  
	}  
	return res;  
} 
ll Fi(ll n)
{
	Matrix base,ans;  
		for (int i = 0; i < MAXN; i++)  
			for (int j = 0; j < MAXN; j++)  
				base.mat[i][j] = 1;  
	base.mat[1][1] = 0; 
	ans = pow_mod(base, n);
	return ans.mat[0][1];
} 
int main()  
{     
	ios::sync_with_stdio(false); 
	ll k;
	while(cin>>k)
	{
		cout<<(Fi(3+2*k)-1)%mod<<endl;
	}
	return 0;  
}  