#include<cstdio>
const int N=60010,M=131100;
int Case,n,i,a[N],ap[N],tag[M];double v[M],t,L,R,MID;
inline double min(double a,double b){return a<b?a:b;}
inline void tag1(int x,int p){tag[x]+=p;v[x]+=p;}
inline void pb(int x){if(tag[x])tag1(x<<1,tag[x]),tag1(x<<1|1,tag[x]),tag[x]=0;}
void build(int x,int a,int b){
  v[x]=MID*a,tag[x]=0;
  if(a==b)return;
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
void change(int x,int a,int b,int c,int d){
  if(c<=a&&b<=d){tag1(x,1);return;}
  pb(x);
  int mid=(a+b)>>1;
  if(c<=mid)change(x<<1,a,mid,c,d);
  if(d>mid)change(x<<1|1,mid+1,b,c,d);
  v[x]=min(v[x<<1],v[x<<1|1]);
}
void ask(int x,int a,int b,int d){
  if(b<=d){
    if(t>v[x])t=v[x];
    return;
  }
  pb(x);
  int mid=(a+b)>>1;
  ask(x<<1,a,mid,d);
  if(d>mid)ask(x<<1|1,mid+1,b,d);
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    L=0,R=1;
    for(int _=20;_;_--){
      MID=(L+R)/2;
      build(1,1,n);
      for(i=1;i<=n;i++)ap[i]=0;
      for(i=1;i<=n;i++){
        change(1,1,n,ap[a[i]]+1,i);
        t=1e9;
        ask(1,1,n,i);
        if(t-MID*(i+1)<=0)break;
        ap[a[i]]=i;
      }
      if(i<=n)R=MID;else L=MID;
    }
    printf("%.10f\n",(L+R)/2);
  }
  return 0;
}