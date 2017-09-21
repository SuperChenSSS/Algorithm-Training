#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstring>
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
	void insert(string buf)
	{
		int len = buf.size();
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
	int query(string buf)
	{
		int len = buf.size();
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
		}
		return res;
	}
};
string buf[100000];
int len[100000];
Trie ac;
int main()
{
  //freopen("2.txt", "r", stdin);
  ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		int maxlen = 0;
		cin >> n;
		ac.init();
		for(int i = 0; i < n; i++)
		{
			cin>>buf[i];
      		len[i]=buf[i].size();
			ac.insert(buf[i]);
			maxlen = max(maxlen,len[i]);
		}
		ac.build();
	    for(int i=0;i<n;i++)
	    {
	      if(len[i]==maxlen)
	      {
	        if(ac.query(buf[i])==n)
	        {
	          cout << buf[i] << endl;
	          break;
	        }
	        else
	        {
	          cout << "No" << endl;
	          break;
	        }
	      }
	    }
	}
	return 0;
}
