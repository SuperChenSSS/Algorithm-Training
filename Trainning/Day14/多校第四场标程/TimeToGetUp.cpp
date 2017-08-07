#include<cstdio>
#include<string>
#include<map>
using namespace std;
int Case,i,j;char a[7][21];
string num[10][7],t,A,B,C,D;
map<string,int>T;
int main(){
  num[0][0]=".XX.";
  num[0][1]="X..X";
  num[0][2]="X..X";
  num[0][3]="....";
  num[0][4]="X..X";
  num[0][5]="X..X";
  num[0][6]=".XX.";
  
  num[1][0]="....";
  num[1][1]="...X";
  num[1][2]="...X";
  num[1][3]="....";
  num[1][4]="...X";
  num[1][5]="...X";
  num[1][6]="....";
  
  num[2][0]=".XX.";
  num[2][1]="...X";
  num[2][2]="...X";
  num[2][3]=".XX.";
  num[2][4]="X...";
  num[2][5]="X...";
  num[2][6]=".XX.";
  
  num[3][0]=".XX.";
  num[3][1]="...X";
  num[3][2]="...X";
  num[3][3]=".XX.";
  num[3][4]="...X";
  num[3][5]="...X";
  num[3][6]=".XX.";
  
  num[4][0]="....";
  num[4][1]="X..X";
  num[4][2]="X..X";
  num[4][3]=".XX.";
  num[4][4]="...X";
  num[4][5]="...X";
  num[4][6]="....";
  
  num[5][0]=".XX.";
  num[5][1]="X...";
  num[5][2]="X...";
  num[5][3]=".XX.";
  num[5][4]="...X";
  num[5][5]="...X";
  num[5][6]=".XX.";
  
  num[6][0]=".XX.";
  num[6][1]="X...";
  num[6][2]="X...";
  num[6][3]=".XX.";
  num[6][4]="X..X";
  num[6][5]="X..X";
  num[6][6]=".XX.";
  
  num[7][0]=".XX.";
  num[7][1]="...X";
  num[7][2]="...X";
  num[7][3]="....";
  num[7][4]="...X";
  num[7][5]="...X";
  num[7][6]="....";
  
  num[8][0]=".XX.";
  num[8][1]="X..X";
  num[8][2]="X..X";
  num[8][3]=".XX.";
  num[8][4]="X..X";
  num[8][5]="X..X";
  num[8][6]=".XX.";
  
  num[9][0]=".XX.";
  num[9][1]="X..X";
  num[9][2]="X..X";
  num[9][3]=".XX.";
  num[9][4]="...X";
  num[9][5]="...X";
  num[9][6]=".XX.";
  for(i=0;i<=9;i++){
    t="";
    for(j=0;j<7;j++)t+=num[i][j];
    T[t]=i;
  }
  scanf("%d",&Case);
  while(Case--){
    for(i=0;i<7;i++)scanf("%s",a[i]);
    A=B=C=D="";
    for(i=0;i<7;i++)for(j=0;j<4;j++){
      A.push_back(a[i][j]);
      B.push_back(a[i][j+5]);
      C.push_back(a[i][j+12]);
      D.push_back(a[i][j+17]);
    }
    printf("%d%d:%d%d\n",T[A],T[B],T[C],T[D]);
  }
  return 0;
}