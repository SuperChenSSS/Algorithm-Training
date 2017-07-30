//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
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
char arr1[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./_+{}|:\"<>?";
char arr2[] = "`1234567890[]\"<>PYFGCRL/=\\AOEUIDHTNs-;QJKXBMWVZ{}?+|S_WVZ";
int main()
{
	freopen("d.in","r",stdin);
	char c;
	int i;
	while((c=getchar())!=EOF)
	{
		for(i=1;arr1[i]&&arr1[i]!=toupper(c);i++);
		/*if(c=='Q')	putchar('"');
		else if(c=='W')	putchar('<');
		else if(c=='E')	putchar('>');
		else if(c=='Z')	putchar(':');
		else if(c==',')	putchar('w');
		else if(c=='.')	putchar('v');
		else if(c=='/')	putchar('z');
		else if(c==';')	putchar('s');
		else if(c=='{')	putchar('?');
		else if(c=='}')	putchar('+');*/
		if(arr1[i] && arr1[i]==c)	putchar(arr2[i]);
		else if(arr1[i]==toupper(c) &&arr1[i]!=c)	putchar(tolower(arr2[i]));
		else	putchar(c);
	}
	return 0;
}
