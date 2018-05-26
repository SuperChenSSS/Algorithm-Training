#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
const int maxn = 1005;
char m[2222];
using namespace std;

int main()
{
	m[12] = 'A';
	m[2111] = 'B';
	m[2121] = 'C';
	m[211] = 'D';
	m[1] = 'E';
	m[1121] = 'F';
	m[221] = 'G';
	m[1111] = 'H';
	m[11] = 'I';
	m[1222] = 'J';
	m[212] = 'K';
	m[1211] = 'L';
	m[22] = 'M';
	m[21] = 'N';
	m[222] = 'O';
	m[1221] = 'P';
	m[2212] = 'Q';
	m[121] = 'R';
	m[111] = 'S';
	m[2] = 'T';
	m[112] = 'U';
	m[1112] = 'V';
	m[122] = 'W';
	m[2112] = 'X';
	m[2122] = 'Y';
	m[2211] = 'Z';
	char tmp[1005];
	int temp,mark,val;
	while(cin>>tmp)
	{

			val = 0;
			temp = 0;
		for(int i=0;i<strlen(tmp);i++)
		{
			if(mark == 1 && tmp[i] == '/')
			{
				printf(" ");
				mark = 0;
				continue;
			}
			else
			{
				mark = 0;
			}
			if(tmp[i]=='.')
			{
				temp = temp * 10;
				temp +=1;
			   // printf("1:%d ",temp);
			}
			else if(tmp[i] == '-')
			{
				temp = temp * 10;
				temp +=2;
				//printf("2:%d ",temp);
			}
			else if(tmp[i] == '/')
			{
				//printf("/:%d ",temp);
				mark = 1;
				printf("%c",m[temp]);
				temp = 0;
				val = 0;
			}
		}
		printf("%c\n",m[temp]);
		//printf("\n");
	}
	return 0;
}