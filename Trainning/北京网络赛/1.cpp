#include<iostream>
using namespace std;
int main()
{
	int p[200],i,j,n,m,a,b,q,x,k,f,mm,aa,bb,sum;
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
			cin>>p[i];
		for(i=n;i<200;i++)
			p[i]=-1;
		cin>>q;
		for(i=0;i<q;i++)
		{
			cin>>x;
			p[x]=-1;
		}
		mm=999999;
		for(i=0;i<n;i++)
		{
			//cout<<"a\n";
			if(p[i]>=0)
			{
				f=1;
				x=999999;
				k=m-1;
				for(j=i+1;j<n;j++)
				{
					if(k)
					{
						if(p[j]>=0)
						{
							k--;
							if(x>p[j])
							{
								x=p[j];
								bb=j;
							}
						}
					}
					else
						if(k==0)break;
						else if(j==n)
						{
							f=0;
							break;
						}
				}
				sum=p[i]+x;
				aa=i;
			}
			//cout<<"b\n";
			if(sum<mm&&f==1)
			{
				a=aa;
				b=bb;
				mm=sum;
			}
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}