#include<cstdio>
int Case,n,x,c[2];
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    c[0]=c[1]=0;
    while(n--)scanf("%d",&x),c[x&1]++;
    printf("2 %d\n",c[0]>c[1]?0:1);
  }
  return 0;
}