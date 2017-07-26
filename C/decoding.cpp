#include<stdio.h>
#include<string.h>
int readchar(){
    for(;;){
        int ch = getchar();
        if(ch != '\n' && ch !='\r')     return ch;//一直读取到非换行符为止
    }
}
int readint(int c){
    int v = 0;
    while(c--)  v = v * 2 + readchar() - '0';
    return v;
}
int code[8][1<<8];
void printcodes(){
    for(int len=1;len<=7;len++)
        for(int i=0;i<(1<<len)-1;i++){
            if(code[len][i] == 0)   return;
            printf("code[%d][%d] = %c\n",len,i,code[len][i]);
        }
}
int readcodes(){
    memset(code,0,sizeof(code));//清空数组
    code[1][0] = readchar();//直接调到下一行开始读取。如果输入已经结束，会读到EOF
    for(int len=2;len<=7;len++){
        for(int i=0;i<(1<<len)-1;i++){
            int ch = getchar();
            if(ch == EOF)   return 0;
            if(ch =='\n' || ch == '\r') return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}
int main(){
    //freopen("d.in","r",stdin);
    while(readcodes()){//无法读取更多编码头时退出
        //printcodes();
        for(;;){
            int len = readint(3);
            if(len == 0)    break;
            //printf("len = %d",len);
            for(;;){
                int v = readint(len);
                //printf("v = %d\n",v);
                if(v == (1 << len) - 1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}