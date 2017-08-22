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
const int maxn = 1e6;
const int mod = (1e9+7); 
struct q
{
	int x,y,z;
}q[30000];
int l,r,c;
int length[30000];
int xx[] = {1,-1,0,0,0,0};
int yy[] = {0,0,0,0,-1,1};
int zz[] = {0,0,-1,1,0,0};
char cell[40][40][40];
bool vis[40][40][40];
int startx,starty,startz;
int bfs()
{
	int rear,front,dx,dy,dz,i;
	memset(vis,false,sizeof(vis));
	memset(length,0,sizeof(length));
	q[0].x = startx;q[0].y = starty;q[0].z = startz;
	front = rear = 0;
	while(front<=rear)
	{
		for(int i=0;i<6;i++)
		{
			dx = q[front].x + xx[i];
			dy = q[front].y + yy[i];
			dz = q[front].z + zz[i];
			if(!vis[dx][dy][dz] && (cell[dx][dy][dz]=='.' || cell[dx][dy][dz]=='E') 
			&& dx>=0 && dx<l && dy>=0 && dy<r && dz>=0 && dz<c)
			{
				vis[dx][dy][dz] = true;
				q[++rear].x = dx;
				q[rear].y = dy;
				q[rear].z = dz;
				length[rear] = length[front] + 1;
				if(cell[dx][dy][dz]=='E')
					return length[rear];		
			}
		}
		front++;
	}
	return 0;	
}
int main()
{
	//freopen("dm.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>l>>r>>c && l!=0 && r!=0 && c!=0)
	{
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
				{
					cin>>cell[i][j][k];
					if(cell[i][j][k]=='S')
						startx = i,starty = j,startz = k;
				}
		int res = bfs();
		if(res)
			printf("Escaped in %d minute(s).\n",res);
		else
			printf("Trapped!\n");
	}
	return 0;
}