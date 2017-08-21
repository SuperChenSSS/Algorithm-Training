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

int H,W;
char t[200][200];
int si,sj,ti,tj;
int d[200][200];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
 
int main()
{
	while(cin>>H>>W)
	{
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cin>>t[i][j];
				if(t[i][j]=='@')
				{
					si=i;
					sj=j;
				}
				if(t[i][j]=='%')
				{
					ti=i;
					tj=j;
				}
			}
		}
		memset(d,1,sizeof(d));
		d[ti][tj]=0;
		queue<int> qi,qj;
		qi.push(ti);
		qj.push(tj);
		while(!qi.empty())
		{
			int pi=qi.front();qi.pop();
			int pj=qj.front();qj.pop();
			for(int dir=0;dir<4;dir++){
				int ni=pi+di[dir];
				int nj=pj+dj[dir];
				if(ni<0||nj<0||ni>=H||nj>=W)
					continue;
				if(t[ni][nj]=='#')
					continue;
				if(d[ni][nj]>d[pi][pj]+1)
				{
					d[ni][nj] = d[pi][pj] + 1;
					qi.push(ni);
					qj.push(nj);
				}
			}
		}
		int dist=d[si][sj];
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
				if(t[i][j]=='$')
					if(d[i][j]<=dist)
						dist=0;
		if(dist)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
		}
		return 0;
}