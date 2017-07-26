#include<iostream>
#include<algorithm>
using namespace std;

int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int endX,endY,startX,startY;
int map[25][25];
int col,row,steps,mini;
#define MAX 1e8
void dfs(int startX,int startY){
	int posX,posY;
	if(steps>=10)//超过10步
		return;
	for(int i=0;i<4;i++){//4个方向
		posX = startX;
		posY = startY;
		while(1){
			posX += dir[i][0];//改变x坐标
			posY += dir[i][1];//改变y坐标
			if(posX<0||posX>row||posY<0||posY>col)//数组越界
				break;
			if(posX==endX&&posY==endY){//到达终点
				steps++;
				if(mini>steps)
					mini = steps;//存储较小的量，最小步数
				steps--;
				return;
			}
			else if(map[posX][posY]==1){//碰到障碍物
				if(posX-dir[i][0]!=startX||posY-dir[i][1]!=startY){//如果不在起点
					map[posX][posY] = 0;//障碍物消失
					steps++;//步数+1
					dfs(posX-dir[i][0],posY-dir[i][1]);//进行dfs
					map[posX][posY] = 1;//障碍物复原
					steps--;//步数-1
				}
				break;
			}
		}
	}
}
int main()
{
	//freopen("d.txt","r",stdin);
	int startX,startY;
	while(cin>>col>>row&&(col||row)){
		for(int i=1;i<=row;i++)
			for(int j=1;j<=col;j++){
				cin>>map[i][j];
				if(map[i][j]==2){//标记起始
					startX = i;
					startY = j;
				}
				if(map[i][j]==3){//标记终点
					endX = i;
					endY = j;
				}
			}
		mini = MAX;
		steps = 0;
		dfs(startX,startY);
		if(mini==MAX)//mini未做改变
			cout<<"-1"<<endl;
		else//mini值改变
			cout<<mini<<endl;
	}
	return 0;
}