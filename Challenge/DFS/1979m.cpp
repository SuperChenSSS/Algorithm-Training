#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
char RedAndBlack[20][20];
int RBState[20][20] = {0};
int w,h;
int result;
int dfs(int a,int b);
int main()
{
    while(cin>>w>>h&&(w||h)){
        int posX = 0;int posY = 0;
        result = 0;
        memset(RedAndBlack,0,sizeof(RedAndBlack));
        memset(RBState,0,sizeof(RBState));
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                cin>>RedAndBlack[i][j];
                if(RedAndBlack[i][j]=='@'){
                    posX = i;
                    posY = j;
                }
            }
        dfs(posX,posY);
        cout<<result + 1 <<endl;
    }
    return 0;
}

int dfs(int a,int b){
    if(a<0||a>=h||b<0||b>=w)
        return 0;
    if(RBState[a][b]==0){
        if(RedAndBlack[a][b]=='#')
            return 0;
        if(RedAndBlack[a][b]=='.')
            result++;
        RBState[a][b] = 1;
        dfs(a+1,b);
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a,b-1);
    }
    return 0;
}