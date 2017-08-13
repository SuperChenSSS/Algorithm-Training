#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int co[10];
int o,x,Count,mark,rival,cotemp;
bool success[11];

bool winjudge(int mar)
{
	for(int f = 0; f<9; ++f)
	{
		if(co[f] == mar)
		{
			if(f == 0||f == 8)
			{
				if(co[0]==co[4]&&co[4] == co[8]&&co[4]==mar)
				{
					return true;
				}
			}
			else if(f == 2 || f == 6)
			{
				if(co[2]==co[4]&&co[4]==co[6])
				{
					return true;
				}
			}
			else if(f == 4)
			{
				if((co[0] == co[8]&&co[0]==co[4])||(co[2]==co[6]&&co[2]==co[4]))
				{
					return true;
				}
			}
			int line = f/3;
			int col = f-line*3;
			if(co[line*3]==co[line*3+1]&&co[line*3+1]==co[line*3+2])
			{
				return true;
			}
			if(co[col]==co[col+3]&&co[col+3]==co[col+6])
			{
				return true;
			}

		}
	}
	return false;
}

int main()
{
	bool flag = false;
	int cotemp,cotemp2;
	int T,i = -1;
	char temp;
	int rivalwincount = 0,blank;
	cin>>T;
	Count = 0;
	while(T--)
	{
		o = 0;
		x = 0;
		rivalwincount = 0;
		while(1)
		{
			//cin>>temp;
			scanf("%c",&temp);
			if(temp == 'o')
			{
				++o;
				co[++i] = -1;
			}
			else if(temp == 'x')
			{
				co[++i] = 1;
				++x;
			}
			else if(temp == '.')
				co[++i] = 0;
			if(i == 8)
			{
				i = -1;
				break;
			}
		}
		//cout<<"x win:"<<winjudge(1);
		//cout<<" o win:"<<winjudge(-1)<<endl;
		temp = '\n';
		while(temp == '\n')scanf("%c",&temp);
		if(temp == 'o')
		{
			mark = -1;
			rival = 1;
			if(o <= 1)
			{
				success[Count] = false;
				++Count;
				continue;
			}
		}
		else
		{
			mark = 1;
			rival = -1;
			if(x <= 1)
			{
				success[Count] = false;
				++Count;
				continue;
			}
		}
		if(o+x == 8)
		{
			int k;
			for(k = 0; k<8; ++k)
				if(co[k] == 0)
					break;
			int line = k/3;
			int col = k-line*3;
			co[k] = mark;
			if(co[line*3]==co[line*3+1]&&co[line*3+1]==co[line*3+2])
			{
				success[Count] = true;
				++Count;
				continue;
			}
			if(co[col]==co[col+3]&&co[col+3]==co[col+6])
			{
				success[Count] = true;
				++Count;
				continue;
			}
			success[Count] = false;
			++Count;
			continue;
		}
		for(int f = 0; f<9; ++f)
		{
			if(co[f] == 0)
			{
				co[f] = mark;
				if(winjudge(mark))
				{
					success[Count] = true;//一步成功
					break;
				}
				co[f] = 0;
			}
		}
		if(success[Count] == false&&o+x != 7)
		{
			for(int f = 0; f<9; ++f)
			{
				if(co[f] == 0)
				{
					co[f] = rival;
					if(winjudge(rival))
					{
						++rivalwincount;
						blank = f;
					}
					co[f] = 0;
				}
			}
			if(rivalwincount==1)
			{
				rivalwincount = 0;
				co[blank] = mark;
				for(int f = 0; f<9; ++f)
				{
					if(co[f]==0)
					{
						co[f] = mark;
						if(winjudge(mark))
						{
							++rivalwincount;
						}
						co[f] = 0;
					}
				}
				if(rivalwincount>1)
				{
					success[Count] = true;
				}
			}
			else if(rivalwincount == 0)
			{
				for(int f = 0; f<9; ++f)
				{
					if(co[f]==0)
					{
						co[f] = mark;
						rivalwincount = 0;
						for(int mp = 0;mp<9;++mp)
						{
							if(co[mp]==0)
							{
								co[mp] = mark;
								if(winjudge(mark))
								{
									++rivalwincount;
									if(rivalwincount>1)
									{
										success[Count]=true;
										break;
									}
								}
								co[mp] = 0;
							}
						}
						co[f] = 0;
						if(success[Count] == true)
						{
							break;
						}
					}
				}
			}
		}
		++Count;
	}
	for(int mt = 0; mt < Count; ++mt)
	{
		if(success[mt])
			printf("Kim win!\n");
		else
			printf("Cannot win!\n");
	}
	return 0;

}