#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1<<20;
int t = 0,t2 = 0;
int strl;
char cards[21];
int cnt1,cnt2;

void flip(int &t,int pos)
{
	if(pos==strl-1)
	{
		t^=(1<<pos);
		t^=(1<<pos-1);
	}
	else if(pos == 0)
	{
		t^=(1);
		t^=(1<<1);
	}
	else
	{
		t^=(1<<pos+1);
		t^=(1<<pos);
		t^=(1<<pos-1);
	}
}

int maelstrom(int b)
{
	int COUNT = 0;
	for(int i = strl-2; i>=0; --i)
	{
		if(b&(1<<(i+1)))
		{
			flip(b,i);
			++COUNT;
		}

	}
	if(b == 0)
		return COUNT;
	else
		return -1;
}



int main()
{
	int pos;
	ios::sync_with_stdio(false);
	int cnt = 0;
	while(cin>>cards)
	{
		t = 0;
		t2 = 0;
		//cin>>cards;
		strl = strlen(cards);
		pos = strl-1;
		for(int i = 0; i<strl; ++i)
		{
			t<<=1;
			if(cards[i] == '1')
			{
				t|=1;
			}
		}
		if(strl == 1)
		{
			if(t&1)
				cnt = 1;
			else
				cnt = 0;
		}
		else
		{
			t2 = t;
			t2^=(1<<pos);
			t2^=(1<<pos-1);
			cnt1 = maelstrom(t);
			cnt2 = maelstrom(t2);
			if(cnt1 == -1)
				if(cnt2 == -1)
					cnt = -1;
				else
					cnt = cnt2 + 1;
			else if(cnt2 == -1)
				cnt = cnt1;
			else
				cnt = min(cnt1,cnt2 + 1);

		}
		if(cnt!= -1)
		{
			printf("%d\n",cnt);
		}
		else
			printf("NO\n");


	}
}