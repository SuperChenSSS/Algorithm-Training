#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn = 1e6;
int n;
struct Trie
{
	int next[500010][26],fail[500010],end[500010];
	int root,L;
	int newnode()
	{
		for(int i = 0; i < 26; i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		for(int i = 0; i < len; i++)
		{
			if(next[now][buf[i]-'a'] == -1)
				next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now]++;
	}
	void build()
	{
		queue<int>Q;
		fail[root] = root;
		for(int i = 0; i < 26; i++)
			if(next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while( !Q.empty() )
		{
			int now = Q.front();
			Q.pop();
			for(int i = 0; i < 26; i++)
				if(next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]]=next[fail[now]][i];
					Q.push(next[now][i]);
				}
		}
	}
	int query(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for(int i = 0; i < len; i++)
		{
			now = next[now][buf[i]-'a'];
			int temp = now;
			while( temp != root )
			{
				res += end[temp];
				end[temp] = 0;
				temp = fail[temp];
			}
			if(res==n)	return res;
		}
		return res;
	}
};
char buf[1000010],zhu[maxn];
Trie ac;
int check(int mlen)
{
	for(int i=1;i<=n;i++)
		if(len[i]==mlen)
		{
			if(ac.query(zhu)==n)
				return i;
			else return 0;
		}
	return 0;
}
int main()
{
	//freopen("2.txt", "r", stdin);
	int T;
	scanf("%d",&T);
	while( T-- )
	{
		int maxlen = 0,flag1 = 0;
		scanf("%d",&n);
		ac.init();
		for(int i = 0; i < n; i++)
		{
			scanf("%s",buf);
			ac.insert(buf);
			if(maxlen<strlen(buf))
			{
				maxlen = strlen(buf);
				//memset(zhu,0,sizeof(zhu));
				strcpy(zhu,buf);
			}
		}
		ac.build();
		check(n);
	}
	return 0;
}