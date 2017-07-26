#include<stdio.h>
#include<string.h>
#define maxn 100
int left,chance;//还需要猜left个位置，错chance次之后就会输
char s[maxn],s2[maxn];//答案是字符串s,玩家猜的字母序列是s2
int win,lose;//win=1表示已经赢了；lose=1表示已经输了

void guess(char ch){
    int bad = 1;
    for(int i=0;i<strlen(s);i++)
        if(s[i] == ch){//如果猜测相同
            left--;
            s[i] = ' ';
            bad = 0;
        }
        if(bad) --chance;
        if(!chance) lose = 1;
        if(!left)   win = 1;
}

int main()
{
    int T;
    while(scanf("%d%s%s",&T,s,s2) == 3 && T != -1){
        printf("Round %d\n",T);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        for(int i=0;i<strlen(s2);i++){
            guess(s2[i]);//猜一个字母
            if(win || lose) break;//成功或失败就跳出
        }
        if(win) printf("You win.\n");
        else if(lose)   printf("You lose.\n");
        else    printf("You chickened out.\n");
    }
    return 0;
}