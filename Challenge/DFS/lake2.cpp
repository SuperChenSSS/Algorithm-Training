#include <iostream>
#include <stdio.h>
using namespace std ;


char RedBlack[30][30] ;
int RedBlackuse[30][30] = {0} ; 
int cont = 0 ;
int row , col ;

int dfs(int posX , int posY ); 

int main() {
	//cout << RedBlackuse[5][5] ;
	int posX , posY ; // 记录@的坐标
	cin >> col >> row ;
	for(int i = 0 ; i < row ; i ++)
	{
		for(int j = 0 ; j < col ; j ++)
		{
			cin >> RedBlack[i][j] ;
			if(RedBlack[i][j] == '@')
			{
				posX = i ; 
				posY = j ;	
			}
		}
	}
	//getchar() ;
	dfs(posX , posY) ;
	cout << cont + 1 << endl ;
	return 0;
}

int dfs(int posX , int posY )
{
	//cout << posX << "  "<< posY << endl;
	//cout << RedBlackuse[posX][posY] <<endl ; 
	if(posX >= row || posY >= col || posX < 0 || posY < 0)
	{
		return  0;
	}
	if(RedBlackuse[posX][posY] == 0)
	{
	//	cout << RedBlack[posX][posY] << endl ;
	//	getchar() ;
		if(RedBlack[posX][posY] == '#')
		{
			return 0 ;
		}
		if(RedBlack[posX][posY] == '.')
		{
			cont ++ ;
		}
		RedBlackuse[posX][posY] = 1 ;
		dfs(posX + 1 , posY) ;
		dfs(posX - 1 , posY) ;
		dfs(posX  , posY + 1) ;
		dfs(posX , posY - 1) ;
	}
	else
	{
		return 0 ;
	}
}