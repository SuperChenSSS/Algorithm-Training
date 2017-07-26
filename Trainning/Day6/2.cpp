//TD2017team01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue>  
using  std::cout;
using std::cin;  
typedef long long ll;  
  
const int INF = 1000000007;  
const int maxn = 1e6+10;
int arr[26][100010];
int value[27];
int rank[27];
int first[26] = {0};
int res[maxn];
char input[maxn];

bool isIbigger(int i,int j,int m)
{
	int k = m;
	while(k>0)
	{
		--k;
		if(arr[i][k]<arr[j][k])
		{
			return false;
		}
		else if(arr[i][k]>arr[j][k])
		{
			return true;
		}
		else if(arr[i][k]==arr[j][k]&&k==0)
		{
			return false;
		}
	}
	return true;
	
	
}
void init()
{
	res[0] = 1;
	for(int i=1;i<maxn;i++)
	{
		res[i] = (res[i-1]* 26)%INF;
	}
}

int main()
{
	init();
	long long sum=0;
	int n,test = 0,number = 0;
	while(cin>>n)
	{
		memset(first,-1,sizeof(first));
		sum = 0;
		memset(rank,0,sizeof(rank));
		memset(arr,0,sizeof(arr));
		int r = 25;
		int temp = 0;
		test++;
		while(n--)
		{
			cin>>input;
			int size_input = strlen(input);
			for(int x=size_input-1,j = 0; x > 0;--x,++j)
			{
				if(input[x]>='a'&&input[x]<='z')
				{
				++arr[input[x]-'a'][j];
				if(first[input[x]-'a']<j)
				    first[input[x]-'a'] = j;
			    }
			}
			
		}
		
		        for(int j = 0;j<26;++j)
				{
					int i;
					for(int ppp = 0;ppp<26;++ppp)
					{
						if(!rank[ppp]&&first[ppp]>-1)
						{
							number = ppp;
							temp = first[ppp];
							break;    
						}
					}
					for(i = 0;i<26;++i)
					{
						if(temp < first[i]&&!rank[i]&&first[i]>-1)
						{
							temp = first[i];
							number = i;
						}
						else if(temp == first[i]&&!rank[i]&&first[i]>-1)
						{
							if(isIbigger(i,temp,first[i]))
							{
								temp = first[i];
								number = i;
							}
						}
					}
					if(!rank[number])
					rank[number] = r--;
				}
				for(int q = 0;q<26;++q)
				for(int r = 0;r<=maxn;++r)
				{
					sum += arr[q][r]*res[r]*rank[q];
				}
				
		
		printf("Case #%d: %d\n",test,sum);
	}
	return 0;
}