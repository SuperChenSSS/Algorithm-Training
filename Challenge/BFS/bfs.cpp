#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 110;
const int maxm = 110;
const int INF = 1e6;
typedef pair<int,int> P;
char maze[maxn][maxm+1];//表示迷宫的字符串数组
int n,m;
int sx,sy;//起点坐标
int gx,gy;//终点坐标
int d[maxn][maxm];//到各个位置的最短距离的数组
//4个方向移动的向量
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

//求从(sx,sy)到(gx,gy)的最短距离
//如果无法到达，则是INF
int bfs(){
    queue<P> que;
    //把所有位置都初始化为INF
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            d[i][j] = INF;
    //将起点加入队列，并把这一地点的距离设置为0
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    //不断循环直到队列的长度为0
    while(que.size()){
        //从队列的最前端取出元素
        P p = que.front();que.pop();
        //如果取出的状态已经是终点，则结束搜索
        if(p.first == gx && p.second == gy) break;
        //4个方向的循环
        for(int i=0;i<4;i++){
            //移动之后的位置记为(nx,ny)
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            //判断是否可以移动以及是否已经访问过(d[nx][ny]!=INF即为已访问过)
            if(dx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]!='#' && d[nx][ny]==INF){
                //可以移动的话，则加入到队列，并且到该位置的距离确定为到p的距离+1
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main()
{
    freopen("bfs-data.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='S'){
                sx = i;
                sy = j;
            }
            if(maze[i][j]=='G'){
                gx = i;
                gy = j;
            }
        }
    int result = bfs();
    cout<<result<<endl;
    return 0;
}