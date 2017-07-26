#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 80
int main()
{
    //freopen("d.in","r",stdin);
    int T;
    char str[4]={'C','H','O','N'};
    scanf("%d",&T);
    while(T--){
        char s[maxn]="";
        double sum = 0.0;
        int count[]={0,0,0,0};
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
            for(int j=0;j<4;j++){
                if(s[i] == str[j]){
                    if(isdigit(s[i+1]))
                        if(isdigit(s[i+2]))
                            count[j] += (s[i+1] - '0') * 10 + s[i+2] - '0';
                        else
                            count[j] += s[i+1] - '0';
                    else
                        count[j]++;
                }
            }
            sum = 12.01 * count[0] + 1.008 * count[1] + 16.00 * count[2] + 14.01 * count[3];
            printf("%.3f\n",sum);
    }
    return 0;
}