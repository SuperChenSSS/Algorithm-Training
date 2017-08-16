//@Team: TDteam01
//@Author: CMY
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
const int maxn = 1e5+2;
const int mod = (1e9+7); 
int table[15][15];
int main()
{
	int tmp = 0,value = 0;
	bool sb = false;
	bool tf[maxn];
	memset(tf,true,sizeof(tf));
	ios::sync_with_stdio(false);
	int e[maxn] = {0},cnt = 0;
	int temp[maxn] = {0};
	int ans = 0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cin>>table[i][j];
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				for(int l=0;l<=9;l++)
				{
					e[cnt++] = table[table[table[table[0][i]][j]][k]][l];
					//cout<<e<<"\n";
				}
		cnt = 0;
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
					for(int l=0;l<=9;l++)
					{
						temp[cnt] = table[e[cnt]][e[cnt]];
						if(temp[cnt] != 0){
							tf[i*1000+j*100+k*10+l] = false;
						}
						++cnt;
					}
		int s = 0;
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
					for(int l=0;l<=9;l++)
					{
						value = i*1000+j*100+k*10+l;
						sb = true;
						for(int m = 0;m <=9 ; ++m)
						{
							if(sb == false)
							    break;
							if(m != i)
							{
							tmp = table[e[value-i*1000+m*1000]][e[value]];
								
							if(tmp == 0)
							{
							   
							   sb = false;
							}
							}
						}
						for(int m = 0;m <=9 ; ++m)
						{
							if(sb == false)
							    break;
							if(m != j)
							{
							tmp = table[e[value-j*100+m*100]][e[value]];
								
							if(tmp == 0)
							{
							//cout<<tmp;
							   sb = false;
							}
							}
							//cout<<tmp;
						}
						for(int m = 0;m <=9 ; ++m)
						{
							if(sb == false)
							    break;
							if(m != k)
							{
								
							tmp = table[e[value-k*10+m*10]][e[value]];
							if(tmp == 0)
							   sb = false;
							}
						}
						for(int m = 0;m <=9 ; ++m)
						{
							if(sb == false)
							    break;
							if(m != l)
							{
							tmp = table[e[value-l+m]][e[value]];
							if(tmp == 0)
							{
								
							   sb = false;
							}
								
							}
						}
						
						for(int m = 0;m <=9 ; ++m)
						{
							if(sb == false)
							    break;
							if(m != e[value])
							{
								
							tmp = table[e[value]][m];
							
							if(tmp == 0)
							   sb = false;

							}						} 
						if(sb == false)
						{
							
						    tf[value] = false;
						}
					}
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				for(int l=0;l<=9;l++)
				{
					value = i*1000+j*100+k*10+l;
					sb = true;
					if(i != j)
					{
					tmp = table[e[value-1000*i+1000*j-100*j+100*i]][e[value]];
					if(tmp == 0)
					    sb = false;
					}
					if(sb)
					{
						if(j!=k)
						{
							tmp = table[e[value-100*j+100*k-10*k+10*j]][e[value]];
						if(tmp == 0)
						    sb = false;
						}
						if(sb)
						{
							if(k!=l)
							{
								
							tmp = table[e[value-10*k+10*l-l+k]][e[value]];
							if(tmp == 0)
							    sb = false;
							}
							if(sb&&l!=e[value])
							{
								tmp = table[e[value+e[value]-l]][l];
								if(tmp == 0)
								    sb = false;
							}
						}
						
					}
					if(sb == false)
					{
					    tf[value] = false;
						//cout<<s++<<" ";
					}
				}
	for(int i = 0;i<10000;++i)
	{
		if(!tf[i])
		{
			//cout<<i<<" ";
			
		    ++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}