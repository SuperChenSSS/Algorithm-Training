#include<stdio.h>
#define maxn 10000
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int num,s[maxn] = {0},count[10] = {0};
        scanf("%d",&num);
        for(int i=1;i<=num;i++){
            s[i] = i;
            if(i/10 == 0)
                count[i]++;
            else if(i/10 >=1 && i/10 <= 9){
                count[i%10]++;
                count[i/10]++;
            }
            else if(i/10 >= 10 && i/10 <= 99){
                count[i%10]++;
                count[i/10%10]++;
                count[i/100]++;
            }
            else if(i/10 >= 100 && i/10 <= 999){
                count[i%10]++;
                count[i/10%10]++;
                count[i/100%10]++;
                count[i/1000]++;
            }
            else{
                count[i%10]++;
                count[i/10%10]++;
                count[i/100%10]++;
                count[i/1000%10]++;
                count[i/10000]++;
            } 
        }
        for(int j=0;j<10;j++)
            if(j == 9)
                printf("%d\n",count[j]);
            else
                printf("%d ",count[j]);
    }
    return 0;
}