#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stdlib.h>
typedef long long ll;
using namespace std;
const int MAXN=1e6+5;
const ll mod = 1e9+7;
int m;
struct trienode
{
	int id;
	trienode *next[26];
	trienode *fail;
};
char pattern[MAXN];
char strx[MAXN];
char str[MAXN];
int num[MAXN];
void inserttrie(trienode* &root,char* key,int idx)
{
	trienode *p=root;
	int len=strlen(key);
	for(int i=0; i<=len-1; i++)
	{
		int k=key[i]-'a';
		if(p->next[k]==NULL)
		{
			p->next[k]=(struct trienode*)malloc(sizeof(struct trienode));
			p->next[k]->fail=NULL;
			p->next[k]->id=0;
			for(int j=0; j<26; j++)
				p->next[k]->next[j]=NULL;
		}
		p=p->next[k];
	}
	p->id=idx;
}
void buildfail(trienode *&root)
{
	queue<trienode*> q;
	q.push(root);
	while(!q.empty())
	{
		trienode* temp=q.front();
		q.pop();
		for(int i=0; i<26; i++)
			if(temp->next[i])
			{
				if(temp==root)
					temp->next[i]->fail=root;
				else
				{
					trienode *p=temp->fail;
					while(p)
					{
						if(p->next[i])
						{
							temp->next[i]->fail=p->next[i];
							break;
						}
						p=p->fail;
					}
					if(!p)
						temp->next[i]->fail=root;
				}
				q.push(temp->next[i]);
			}
	}
}
void query(trienode *&root)
{
	memset(num,0,sizeof(num));
	trienode *p=root;
	int len=strlen(str);
	for(int i=0; i<=len-1; i++)
	{
		if(str[i]<'a'||str[i]>'z')
		{
			p=root;
			continue;
		}
		int k=str[i]-'a';
		while(!p->next[k]&&p!=root)
			p=p->fail;
		p=p->next[k];
		if(!p)
			p=root;
		trienode *temp=p;
		while(temp!=root)
		{
			if(temp->id>0)
				num[temp->id]++;
			temp=temp->fail;
		}
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	int T;
	cin >> T;
	while(T--)
	{
		trienode *root=(struct trienode*)malloc(sizeof(struct trienode));
		root->fail=NULL;
		root->id=0;
		for(int i=0; i<26; i++)
			root->next[i]=NULL;
		getchar();
		gets(str);
		gets(pattern);
		int ptlen = strlen(pattern);
		int idx=0;
		for(int i=0; i<=ptlen; i++)
		{
			strcpy(strx,pattern+i);
			idx++;
			//puts(strx);
			inserttrie(root,strx,idx);
		}
		buildfail(root);
		query(root);
		long long ans = 0;
		for(int i=1; i<=ptlen+1; i++)
		{
			ans=(ans+num[i]*(ptlen-i+1))%mod;
		}
		cout << ans <<endl;
	}
	return 0;
}