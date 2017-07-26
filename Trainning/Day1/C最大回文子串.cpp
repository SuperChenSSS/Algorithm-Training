#include <iostream>
#include <cstdio>
#include <cstring>
#include <string> 
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e6;
char str[maxn];
int p[maxn*2];
char a[maxn*2];
/*
Manacher算法:匹配最长回文算法，复杂度O(n)
这里变量的含义：
P[i]代表以i为中心时能够到达最远的字符。
maxLine实际上就代表已经扫描到的最右边的字符，即maxLine=P[ID]+ID。
ID代表当前使得扫描到最右边字符的那个位置上的字符。
maxResult 就是记录最终的结果值，即找到最大的那个P[i]。
*/
void result()
{
	int maxLine = 0,ID = 1,maxResult = 0;
	int n = 0,len,lentmp;
	lentmp = strlen(str);
	len = lentmp *2;
	for(int i=0;i<maxn*2;i++)
	{
		p[i] = 0;
		a[i] = '#';
	}
	for(int i=0;i<lentmp;i++)
		a[(i+1)*2-1] = str[i];
	for(int i=1;i<len;i++)
	{
		if(maxLine > i)
			p[i] = min(p[2*ID-i],maxLine-i);
		else
			p[i] = 1;
		while(a[i+p[i]]==a[i-p[i]])
			p[i]++;
		if(p[i]+i>maxLine)
		{
			maxLine = p[i] + i;
			ID = i;
		}
		if(p[i]>maxResult)
			maxResult = p[i];
	}
	cout<<maxResult-1<<endl;
}

int main()
{
	int count = 1;
	while(cin>>str && strcmp(str, "END")!=0)
		{
			cout<<"Case "<<count++<<": ";
			result();
		}
	return 0;
}