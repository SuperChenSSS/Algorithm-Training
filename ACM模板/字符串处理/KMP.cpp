#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using std::cout;
using std::cin;
/*
	next[]的含义：x[i-next[i]...i-1] = x[0...next[i]-1]
	next[i]为满足x[i-z...i-1] = x[0...z-1]的最大z值（就是x的自身匹配）
*/
void kmp_pre(char x[],int m,int next[])
{
	int i,j;
	j = next[0] = -1;
	i = 0;
	while (i<m) {
		while(j!=-1 && x[i]!=x[j])
			j = next[j];
		next[++i] = ++j;
	}
}
/*
	kmpNext[]的意思：next[i] = next[next[...[next[i]]]](直到next[i]<0或者x[next'[i]]!=x[i])
	这样的预处理可以快一些
*/
void preKMP(char x[],int m,int kmpNext[])
{
	int i,j;
	j = kmpNext[0] = -1;
	i = 0;
	while(i<m)
	{
		while(j!=-1 && x[i]!=x[j])
			j = kmpNext[j];
		if(x[++i] == x[++j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
	}	
}
//返回x在y中出现的次数，可以重叠
int next[100010];
int KMP_Count(char x[],int m,char y[],int n)
{//x是模式串，y是主串
	int i,j;
	int ans = 0;
	//preKMP(x,m,next);
	kmp_pre(x,m,next);
	i = j = 0;
	while(i<n)
	{
		while(j!=-1 && y[i]!=x[j])
			j = next[j];
		i++;j++;
		if(j>=m)
		{
			ans++;
			j = next[j];
		}
	}		
	return ans;
}	
int main()
{
		
	return 0;
}