//TDteam01
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
struct st{
	long long x,y,v;
	int q;
	int xx;
}a[50005];
bool cmp(st a,st b){
	if(a.xx<b.xx) return true;
	else if(a.xx==b.xx){
		return a.y*b.x<a.x*b.y;
	}
	else return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int ans1=0,ans2=0,ans3=0,ans4=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].v;
			if(a[i].x>0&&a[i].y>=0){
				ans2++;
				a[i].xx=2;
				a[i].q=1;
			}
			else if(a[i].x<=0&&a[i].y>0){
				ans3++;
				a[i].xx=3;
				a[i].q=-1;
			}
			else if(a[i].x<0&&a[i].y<=0){
				ans4++;
				a[i].xx=4;
				a[i].q=1;
			}
			else {
				ans1++;
				a[i].xx=1;
				a[i].q=-1;
			}
		}
		sort(a+1,a+1+n,cmp);
		long long sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			if(i<=ans1+ans2) sum1+=a[i].v;
			else sum2+=a[i].v;
			a[i].x=abs(a[i].x);
			a[i].y=abs(a[i].y);
		}
		long long result=0;
		int d=ans1+ans2+1;
		for(int i=1;;){
			if(i>ans1+ans2&&d>n) break;
			if(i>ans1+ans2){
				result=max(sum1*sum2,result);
				sum1+=a[d].v;
				sum2-=a[d].v;
				d++;
			}
			else if(d>n){
				result=max(sum1*sum2,result);
				sum1-=a[i].v;
				sum2+=a[i].v;
				i++;
			}
			else if(a[i].q*a[i].y*a[d].x<a[d].q*a[d].y*a[i].x){
				result=max(sum1*sum2,result);
					sum1=sum1-a[i].v;
					sum2=sum2+a[i].v;
					i++;
			}
			else {
			   result=max(sum1*sum2,result);
			   sum1=sum1+a[d].v;
			   sum2=sum2-a[d].v;
			   d++;
			}
		}
		result=max(sum1*sum2,result);
		cout<<result<<endl;
	}
	return 0;
}