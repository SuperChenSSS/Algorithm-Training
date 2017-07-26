#include<stdio.h>
#include<string.h>
#define maxn 85
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        char s[maxn],value = 1,sum = 0;
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++){
               if(s[i]=='O'){
                    sum += value;
                    value++;
               }
               else if(s[i]=='X'){ 
                   value = 1;
               }
        }
        printf("%d\n",sum);
    }
    return 0;
}