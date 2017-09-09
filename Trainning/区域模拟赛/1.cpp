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
bool cmp(int i,int j)
{
	return i>j;
}
int state[300];
int value[300];
int main()
{
	//freopen("2.txt","r",stdin);
	//ios::sync_with_stdio(false);
	ll n,t;
	int p = 1;
	cin>>t;
	while(t--)
	{
		int temp,l,cnt = 0,sss = 0;
		bool f = false;
		memset(state,0,sizeof(state));
		memset(value,0,sizeof(value));
		cin>>n;

		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			value[abs(100-temp)]++;
		}
		for(int i = 0;i<105;++i)
		{
			if(value[i]!=0)
			{
			    l = i;
			    break;
			}
		}
		temp = value[l];
		for(int i = l+1;i<105;++i)
		{
			if(value[i]!=0)
			{
				++sss;
				if(value[i]!=temp&&sss>1)
				f = true;
				break;
			}
		}
		if(f&&n>1)
		{
	     	temp = value[l];
	     	for(int i = l ;i < 105;++i)
	     	{
			    if(value[i]!=0)
			    {
			      	if(value[i]>temp)
				    temp = value[i];
			    }
	    	}
	        for(int i = l;i<105;++i)
	        {
		         if(value[i]!=0)
		         {
			         if(value[i] == temp)
			               state[cnt++] = i;
	         	}
         	}
            sort(state,state+cnt,cmp);
printf("Case #%d:\n",p++);
for(int i = 0;i < cnt;++i)
{
	printf("%d",10000-state[i]*state[i]);
	if(i != cnt-1)
	printf(" ");
}
printf("\n");
            
		}
		else if(n>1) {
		printf("Case #%d:\n",p++);
			printf("Bad Mushroom\n");
		}
		else
		{
			
			printf("Case #%d:\n",p++);
			printf("%d",10000-l*l);
		}
		
		
	}
			
	return 0;
}