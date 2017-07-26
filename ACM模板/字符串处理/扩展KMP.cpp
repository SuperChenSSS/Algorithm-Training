#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
/*
	扩展KMP算法
	next[i]:x[i...m-1]与x[0...m-1]的最长公共前缀
	extend[i]:y[i...n-1]与x[0...m-1]的最长公共前缀
*/
void pre_EKMP(char x[],int m,int next[])
{
	next[0] = m;
	int j = 0;
	while(j+1<m && x[j]==x[j+1])	j++;
	next[1] = j;
	int k = 1;
	for(int i=2;i<m;i++)
	{
		int p = next[k] + k -1;
		int L = next[i-k];
		if(i+L<p+1)
			next[i] = L;
		else
		{
			j = max(0,p-i+1);
			while (i+j<m && x[i+j] == x[j])
				j++;
			next[i] = j;
			k = i;
		}
	}
}
void EKMP(char x[],int m,char y[],int n,int next[],int extend[])
{
	pre_EKMP(x,m,next);
	int j = 0;
	while(j<n && j<m &&x[j]==y[j])	j++;
	extend[0] = j;
	int k =0 ;
	for(int i=1;i<n;i++)
	{
		int p = extend[k] + k - 1;
		int L = next[i-k];
		if(i+L<p+1)
			extend[i] = L;
		else
		{
			j = max(0,p-i+1);
			while(i+j<n && j<m &&y[i+j]==x[j])	j++;
			extend[i] = j;
			k = i;
		}
	}
}
int main() {
	
	return 0;
}