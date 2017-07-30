#include<cstdio>  
#include<cstring>  
#include<algorithm>   
using namespace std;  
int main()  
{  
	char ch1[70]={"_-+=QWERTYUIOP{}qwertyuiop[]SDFGHJKL:\"sdfghjkl;'ZXCVBN<>?zxcvbnm,./"};  
	char ch2[70]={"{[}]\"<>PYFGCRL?+',.pyfgcrl/=OEUIDHTNS_oeuidhtns-:QJKXBWVZ;qjkxbmwvz"};  
	char ch[120];  
	int shu[120];  
	int n;  
	char a;  
	while (~scanf("%c",&a))  
	{  
		if (a=='\n') printf("\n");  
		else  
		{  
			int tt=1;  
			for (int j=0;j<70;j++)  
			{  
				if (a==ch1[j])  
				{  
					tt=0;  
					printf("%c",ch2[j]);  
					break;  
				}  
			}  
			if (tt)  
			printf("%c",a);  
		}  
	}  
	return 0;  
}  