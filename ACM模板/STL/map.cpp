#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 

int main()
{
	ios::sync_with_stdio(false);
	map<int,const char*> m;//声明int为键，const char*为值
	//插入元素
	m.insert(make_pair(1, "One"));
	m.insert(make_pair(10, "Ten"));
	m[100] = "Hundred";
	//查找元素
	map<int,const char*>::iterator ite;
	ite = m.find(1);
	puts(ite->second);
	ite = m.find(2);
	if(ite==m.end())
		puts("Not Found");
	else
		puts(ite->second);
	puts(m[10]);
	//删除元素
	m.erase(10);
	//遍历所有元素
	for(ite=m.begin();ite!=m.end();ite++)
		printf("%d: %s\n",ite->first,ite->second);
	return 0;
}