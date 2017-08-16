//@Team: TDteam01
//@Author: CMY
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
string arr,out,wrd,cu1,cu2;
int co1,co2;
bool A(char c)
{
	if(c>='A' && c<='Z')
		return 1;
	else
		return 0;
}
bool B(char c)
{
	if(c>='a' && c<='z')
		return 1;
	else
		return 0;
}
void clear()
{
	cu1 = cu2 = "";
	co1 = co2 = 0;
}
int main()
{
	while(getline(cin,arr))
	{
		out = "";
		clear();
		for(int i=0;i<arr.size();i++)
		{
			int j;
			int fup = 0,icd = 0;
			for(j=i;j<arr.size();j++)
			{
				if(A(arr[j])||B(arr[j]));
				else	break;
				wrd += arr[j];
				if(j==i && A(arr[j]))	fup = 1;
				if(j!=i && A(arr[j]))	fup = 0;
				if(B(arr[j]))	icd = 1;
			}
			if(fup && icd)
			{
				if(co1 && co2 == 0)
					co2 = 1;
				if(co1 == 0)
					co1 = 1;
				cu1 += arr[i],cu2 += wrd + arr[j];
			}
			else
			{
				if(co2==0)	
					out += cu2,clear();
				if(co2==1)	
				{
					out += cu1 + " (" + cu2.substr(0,cu2.size()-1) + ")" + cu2[cu2.size()-1];
					clear();
				}
				out += wrd;
				if(j!=arr.size())
					out += arr[j];
			}
			if(arr[j]!=' ' && j!=arr.size())
			{
				if(co2==0)	
					out += cu2,clear();
				if(co2==1)	
				{
					out += cu1 + " (" + cu2.substr(0,cu2.size()-1) + ")" + cu2[cu2.size()-1];
					clear();
				}
			}
			i = j;
			wrd = "";
		}
		if(arr[arr.size()-1]==' ')
		{
			if(co2==0)  
				out+=cu2,clear();  
			if(co2==1)  
			{
				out+=cu1 + " (" + cu2.substr(0,cu2.size()-1)+")" + cu2[cu2.size()-1];
				clear();
			}  
		}  
		else  
		{  
			if(co2==0)  
				out+=cu2.substr(0,cu2.size()-1),clear();  
			if(co2==1)  
			{
				out+=cu1 + " (" + cu2.substr(0,cu2.size()-1) + ")";
				clear();
			}  
		} 
		cout<<out<<"\n";
	}
	return 0;
}