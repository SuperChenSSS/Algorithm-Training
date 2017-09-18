#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
vector<int> vec;
int main()
{
	ios::sync_with_stdio(false);
	int n,tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		vec.push_back(tmp);
	}
	while(!vec.empty())
	{
		tmp = vec[0];
		cout<<vec[0];
		vec.erase(vec.begin());
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]>=tmp)
			{
				cout<<" "<<vec[i];
				tmp = vec[i];
				vec.erase(vec.begin()+i);
				i--;
			}
		}
		cout<<endl;
	}
	return 0;
}