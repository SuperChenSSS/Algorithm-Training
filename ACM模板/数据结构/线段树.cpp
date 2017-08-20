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
const int maxind = 256;  
int segTree[maxind * 4 + 10];  
int arr[maxind]; 
/* 构造函数，得到线段树 */  
void build(int node, int begin, int end)    
{    
	if (begin == end)    
		segTree[node] = arr[begin]; /* 只有一个元素,节点记录该单元素 */  
	else    
	{     
		/* 递归构造左右子树 */   
		build(2*node, begin, (begin+end)/2);    
		build(2*node+1, (begin+end)/2+1, end);   
		   
		/* 回溯时得到当前node节点的线段信息 */    
		if (segTree[2 * node] <= segTree[2 * node + 1])    
			segTree[node] = segTree[2 * node];    
		else    
			segTree[node] = segTree[2 * node + 1];    
	}    
}  
int query(int node, int begin, int end, int left, int right)    
{   
	int p1, p2;    
	
	/*  查询区间和要求的区间没有交集  */  
	if (left > end || right < begin)    
		return -1;    
	
	/*  if the current interval is included in  */    
	/*  the query interval return segTree[node]  */  
	if (begin >= left && end <= right)    
		return segTree[node];    
	
	/*  compute the minimum position in the  */  
	/*  left and right part of the interval  */   
	p1 = query(2 * node, begin, (begin + end) / 2, left, right);   
	p2 = query(2 * node + 1, (begin + end) / 2 + 1, end, left, right);    
	
	/*  return the expect value  */   
	if (p1 == -1)    
		return p2;    
	if (p2 == -1)    
		return p1;    
	if (p1 <= p2)    
		return  p1;    
	return  p2;      
}
/*void updata(int node, int begin, int end, int ind, int add)//单节点更新   
{    
	
	if( begin == end )    
	{    
		segTree[node] += add;    
		return ;    
	}    
	int m = ( left + right ) >> 1;    
	if(ind <= m)    
		updata(node * 2,left, m, ind, add);    
	else    
		updata(node * 2 + 1, m + 1, right, ind, add);    
	//回溯更新父节点    
	segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);     		 
}*/   
int main()  
{  
	arr[0] = 1, arr[1] = 2,arr[2] = 2, arr[3] = 4, arr[4] = 1, arr[5] = 3;  
	build(1, 0, 5);  
	for(int i = 1; i<=20; ++i)  
	 cout<< "seg"<< i << "=" <<segTree[i] <<endl;  
	return 0;  
} 