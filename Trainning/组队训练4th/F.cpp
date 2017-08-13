/*Alice and Bob are playing a stone game in a board of n*mn*m cells.
In the begining, the stone is in the upperleft cell. And in each turn, they can move the stone one cell to the right or one cell down, or diagonally kk cells down to the right, which means if you are at (x,y)(x,y), then you could move into (x+1,y)(x+1,y), (x,y+1)(x,y+1) or (x+k,y+k)(x+k,y+k) at the next step. The player who can not move loses. They play in turns and Alice moves first.

Now given nn, mm and kk, could you tell me who is the winner?
Input
First line contains an integer T(1≤T≤10)T(1≤T≤10), denoting the number of test cases.

In each test case, the first line is two integers QQ and kk.
In the following Q lines, each line contains nn and mm.(1≤Q≤1000,1≤k,n,m≤109)(1≤Q≤1000,1≤k,n,m≤109)
Output
For each test case, output Q lines.
If Alice is the winner, output ``Alice''. Otherwise ``Bob''.
Sample Input
2
2 1
4 5
3 4
2 3
4 5
5 6
Sample Output
Alice
Alice
Alice
Bob
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll maxn = 1<<30;
int T,q,k;
int n,m;

int main()
{
	//freopen("Alice and Bob.txt","r",stdin);
	int temp = 0;
	int temp1 = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&q,&k);

		for(int i = 0; i<q; ++i)
		{
			scanf("%d%d",&n,&m);
			if(m>n)
			{
				m = m^n;
				n = m^n;
				m = m^n;
			}
			if(k == 1)
			{
				if(m & 1)
				{
					if((n - m) & 1)
						printf("Alice\n");
					else
						printf("Bob\n");
				}
				else
				{
					printf("Alice\n");
				}
			}
			else
			{
				temp=m/(k+1);
				temp1=m%(k+1);
				if(temp1==0)
					printf("Alice\n");
				else if(!(temp&1)^((n-m)&1))
					printf("Bob\n");
				else
					printf("Alice\n");

			}

		}
	}
}