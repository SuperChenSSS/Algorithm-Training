#include<iostream>
using namespace std;
const int MAX = 1e8;
int startX,startY,endX,endY;
int arr[20][20];
int add[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int col,row,mini,steps;
void dfs(int posX,int posY);
int main()
{
    freopen("d.txt","r",stdin);
    while(cin>>col>>row&&(col||row)){
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                cin>>arr[i][j];
                if(arr[i][j]==2){startX = i;startY = j;}
                if(arr[i][j]==3){endX = i;endY = j;}
            }
        mini = MAX;steps = 0;
        dfs(startX,startY);
        if(mini==MAX)
            cout<<"-1"<<endl;
        else
            cout<<mini<<endl;
    }
    return 0;
}
void dfs(int posX,int posY){
    if(steps>=10)
        return;
    for(int i=0;i<4;i++){
        int tmpX = posX;
        int tmpY = posY;
        while(1){
            tmpX += add[i][0];
            tmpY += add[i][1];
            if(tmpX<0||tmpX>=row||tmpY<0||tmpY>=col)
                break;
            if(tmpX==endX&&tmpY==endY){
                steps++;
                if(mini>steps)
                    mini = steps;
                steps--;
                return;
            }
            else if(arr[tmpX][tmpY]==1){//碰到障碍物
                if(tmpX-add[i][0]!=posX||tmpY-add[i][1]!=posY){
                    arr[tmpX][tmpY] = 0;
                    steps++;
                    dfs(tmpX-add[i][0],tmpY-add[i][1]);
                    arr[tmpX][tmpY] = 1;
                    steps--;
                }
                break;
            }
        }
    }
}