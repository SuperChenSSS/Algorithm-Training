#include <iostream>
using namespace std;
const int maxn = 105;
int n,m;
char field[maxn][maxn+1];
//现在位置（x,y）
void dfs(int x,int y){
    //将现在所在位置替换为.
    field[x][y] = '.';
    //循环遍历移动的8个方向
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++){
            //想x方向移动dx,向y方向移动dy，移动的结果为(nx,ny)
            int nx = x + dx;
            int ny = y + dy;
            //判断(nx,ny)是不是在园子内，以及是否有积水
            if(nx>=0 && nx<n && ny>=0 && ny<m && field[nx][ny]=='W')
                dfs(nx,ny);
        }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>field[i][j];
    int result = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(field[i][j]=='W'){
                //从有W的地方开始dfs
                dfs(i,j);
                result++;
            }
    cout<<result<<endl;
    return 0;
}