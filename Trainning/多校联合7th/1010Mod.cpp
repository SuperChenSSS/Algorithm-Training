//@Team: TDteam01
//@Author: CMY
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
const int N = 1e6;
using namespace std;
int a[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T --){
		int n , m;
		scanf("%d%d",&n , &m);
		for(int i = 1 ; i <= n ; i ++){
			scanf("%d",&a[i]);
		}
		while(m){
			int x = m & -m;
			for(int i = x + 1 ; i <= n ; i ++){
				a[i] ^= a[i - x];
			}
			m -= x;
		}
		for(int i = 1 ; i <= n ; i ++){
			printf("%d",a[i]);
			if(i == n) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}