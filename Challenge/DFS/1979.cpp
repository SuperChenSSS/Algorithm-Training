#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
using namespace std;

char arr[30][30];
int arrstat[30][30] = {0};
int cont = 0;
int row, col;

int dfs(int posX, int posY);

int main()
{
    freopen("1979.txt","r",stdin);
    int posX, posY; // 记录@的坐标
    while (cin >> col >> row && (col || row))
    {
        cont = 0;
        memset(arr, 0, sizeof(arr));
        memset(arrstat, 0, sizeof(arrstat));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                {
                    posX = i;
                    posY = j;
                }
            }
        dfs(posX, posY);
        cout << cont + 1 << endl;
    }
    return 0;
}

int dfs(int posX, int posY)
{
    if (posX >= row || posY >= col || posX < 0 || posY < 0)
        return 0;
    if (arrstat[posX][posY] == 0)
    {
        if (arr[posX][posY] == '#')
            return 0;
        if (arr[posX][posY] == '.')
            cont++;
        arrstat[posX][posY] = 1;
        dfs(posX + 1, posY);
        dfs(posX - 1, posY);
        dfs(posX, posY + 1);
        dfs(posX, posY - 1);
    }
    return 0;
}