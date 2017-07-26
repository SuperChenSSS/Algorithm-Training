/*
思路：对流星雨排序，然后将地图的每个点的值设为该点最早被炸毁的时间。
如果起点一开始就炸毁的话，那小文青就直接洗剪吹，否则bfs
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int map[500][500];
bool visited[500][500];
typedef struct Meteor
{
    int x;
    int y;
    int t;
}P;
Meteor m[50000];
int n;
const int direction[5][2] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1},
    {0,0},
};
int last;

int bfs()
{
    memset(visited,0,sizeof(visited));
    queue<P> que;
    P current;
    current.x = 0;
    current.y = 0;
    //当前花费时间
    current.t = 0;
    que.push(current);
    while(que.size()){
        //做个备份
        const P p = que.front();que.pop();
        for(int i=0;i<4;i++){
            current = p;
            current.x += direction[i][0];
            current.y += direction[i][1];
            ++current.t;

            if(current.x>=0&&current.y>=0&&map[current.x][current.y]>current.t&&
                    !visited[current.x][current.y]){
                        visited[current.x][current.y] = true;
                        //爆炸时间大于当前时间，是安全的
                        if(map[current.x][current.y]>last)
                            //当前位置爆炸时间大于流星雨最晚落下的时间，说明跑出了流星雨区域
                            return current.t;
                        que.push(current);
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("3669.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>m[i].x>>m[i].y>>m[i].t;
    //地图中的每个点的值表示最早在什么时候被炸毁
    memset(map,0x7f,sizeof(map));
    for(int i=0;i<n;i++){
        last = max(last,m[i].t);
        for(int j=0;j<5;j++){
            int tmpX = m[i].x + direction[j][0];
            int tmpY = m[i].y + direction[j][1];
            if(tmpX>=0&&tmpY>=0&&map[tmpX][tmpY]>m[i].t)
                map[tmpX][tmpY] = m[i].t;
        }
    }
    if(map[0][0] == 0){
        cout<<-1<<endl;
    }
    else
        cout<<bfs()<<endl;
    return 0;
}