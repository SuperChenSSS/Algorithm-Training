/* 
题意：将n拆分成多个正整数之和，问有多少种拆法？ 
如5=1+1+1+1+1=1+1+1+2=1+1+3=1+4=5=1+2+2=2+3.共7种 
 
Input: 
2 
100000 
99999 
 
Output: 
49037875  
677525748 
 
方法： 
直接公式：f[n]=∑(-1)^(k-1)*(f[n-k*(3*k-1)/2]+f[n-k*(3*k+1)/2]) 
			其中n-k*(3*k-1)/2>=0,n-k*(3*k+1)/2>=0； 
		注意两个条件要分开判断，有大于0的就加上相应的f，不是两个同时成立或者不成立 
*/ 
#include <stdio.h>  
#include <math.h>  
#include <string.h>  
#include <iostream>  
using namespace std;  
const int mod=1e9+7;  
int f[100010];  
void init()  
{  
	f[0]=1;  
	int i,j,k,flag=1;  
	for(i=1;i<=100000;i++)  
	{  
		f[i]=0;  
		for(j=1;;j++)  
		{  
			int t=i-j*(3*j-1)/2;  
			int tt=i-j*(3*j+1)/2;  
			if(j&1)  
				flag=1;  
			else  
				flag=-1;  
			if(t<0 && tt<0)  
				break;  
			if(t>=0)  
				f[i]=(f[i]+flag*f[t])%mod;  
			if(tt>=0)  
				f[i]=(f[i]+flag*f[tt])%mod;  
		}  
		f[i]=(f[i]+mod)%mod;  
	}  
}  
int main()  
{  
	init();  
	int T;  
	cin>>T;  
	while(T--)  
	{  
		int n;  
		cin>>n;  
		cout<<f[n]<<endl;  
	}  
	return 0;  
}  
