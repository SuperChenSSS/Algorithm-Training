//TDteam01
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>

using namespace std;
int T;
char clc[7][21];
int ans[4];

int cnt;
int pos;

int posadv()
{
	switch(pos)
	{
	case 0:
		pos = 5;
		break;
	case 5:
		pos = 12;
		printf(":");
		break;
	case 12:
		pos = 17;
		break;
	default:
		pos = 30;
	}
}

int main()
{
	//freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		pos = 0;
		for(int i = 0; i<7; ++i)
		{
			cin>>clc[i];
		}
		while(pos!=30)
		{
			if(clc[3][pos+1]!='X')
			{
				if(clc[0][pos+1]!='X')
				{
					printf("1");
					posadv();
					continue;
				}
				else if(clc[1][pos]!='X')
				{
					printf("7");
					posadv();
					continue;
				}
				else
				{
					printf("0");
					posadv();
					continue;
				}
			}
			else if(clc[1][pos]!='X')
			{
				if(clc[4][pos]!='X')
				{
					printf("3");
					posadv();
					continue;
				}
				else
				{
					printf("2");
					posadv();
					continue;
				}
			}
			else if(clc[1][pos+3]!='X')
			{
				if(clc[4][pos]!='X')
				{
					printf("5");
					posadv();
					continue;
				}
				else
				{
					printf("6");
					posadv();
					continue;
				}
			}
			else if(clc[0][pos+1]=='X')
			{
				if(clc[4][pos]!='X')
				{
					printf("9");
					posadv();
					continue;
				}
				else
				{
					printf("8");
					posadv();
					continue;
				}
			}
			else
			{
					printf("4");
					posadv();
					continue;
			}

		}
		printf("\n");

	}
	return 0;
}