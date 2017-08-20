#include <assert.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#define maxn 100009
using namespace std;
int n;
int a[maxn], v[maxn], L;
bool del[maxn];
struct Ant{
	int pos, v, id;
	
	Ant(int _pos = 0, int _v = 0, int _id = 0){
		pos = _pos;
		v = _v;
		id = _id;
	}
	
	bool operator < (const Ant &rhs) const{
		return pos < rhs.pos;
	}
}ant[maxn];

stack<Ant>stk;

bool Catch(Ant a, Ant b){
	return 1LL * a.pos * b.v <= 1LL * b.pos * a.v;
}

bool beat(Ant a, Ant b){
	return a.id > b.id;
}

pair<long long, long long> solve0(int x){
	for(int i = n; i >= x; i--){
		if(ant[i].v < 0)
			continue;
		Ant cur = ant[i];
		cur.pos = L - cur.pos;
		bool ok = 1;
		while(!stk.empty() && Catch(cur, stk.top())){
			if(beat(cur, stk.top())){
				stk.pop();
			}
			else{
				ok = 0;
				break;
			}
		}
		if(ok)
			stk.push(cur);
		//cout << ok << endl;
	}
	long long fz = 0, fm = 1;
	while(!stk.empty()){
		if(fz * stk.top().v < fm * stk.top().pos){
			fz = stk.top().pos;
			fm = stk.top().v;
		}
		stk.pop();
	}
	return make_pair(fz, fm);
}

pair<long long, long long>  solve1(int x){
	for(int i = 2; i <= x; i++){
		if(ant[i].v > 0)
			continue;
		Ant cur = ant[i];
		cur.v = -cur.v;
		//cout << cur.pos << " " << cur.v << " " << cur.id << endl;
		bool ok = 1;
		while(!stk.empty() && Catch(cur, stk.top())){
			if(beat(cur, stk.top())){
				stk.pop();
			}
			else{
				ok = 0;
				break;
			}
		}
		if(ok)
			stk.push(cur);
		//cout << ok << endl;
	}
	long long fz = 0, fm = 1;
	while(!stk.empty()){
		if(fz * stk.top().v < fm * stk.top().pos){
			fz = stk.top().pos;
			fm = stk.top().v;
		}
		stk.pop();
	}
	return make_pair(fz, fm);
}

int main(){
	int tt;
	scanf("%d", &tt);
	while(tt--){
		scanf("%d%d", &n, &L);
        assert(2 <= n && n <= 100000);
        assert(1 <= L && L <= 1000000000);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
            assert(0 <= a[i] && a[i] <= L - 1);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
            assert(-1000000000 <= v[i] && v[i] <= 1000000000);
		}
		for(int i = 1; i <= n; i++)
			v[i] -= v[n];
		for(int i = 1; i <= n; i++){
			a[i] -= a[n];
			if(a[i] < 0)
				a[i] += L;
		}
		
		for(int i = 1; i <= n; i++)
			del[i] = 0;
			
		for(int i = 1; i <= n; i++){
			ant[i] = Ant(a[i], v[i], i);
		}
		
		sort(ant + 1, ant + 1 + n);
		
		int mx = 0;
		for(int i = 2; i <= n; i++){
			if(ant[i].v > 0){
				mx = max(mx, ant[i].id);
			}
			else{
				if(ant[i].id < mx){
					del[i] = 1;
				}
				else{
					mx = 0;
				}
			}
		}
		
		int pos = -1;
		for(int i = n; i > 1; i--){
			if(ant[i].v < 0 && !del[i]){
				pos = i;
				break;
			}
		}
		
		pair<long long, long long>ans, ans1, ans2;
		
		//cout << pos << endl;
		
		if(pos == -1){
			ans = solve0(2);	
		}
		else{
			ans1 = solve0(pos + 1);
			ans2 = solve1(pos);
			//ans = max(solve0(pos + 1), solve1(pos));
			if(ans1.first * ans2.second > ans2.first * ans1.second)
				ans = ans1;
			else
				ans = ans2;
		}
		long long fz = ans.first;
		long long fm = ans.second;
		long long g = __gcd(fz, fm);
		printf("%lld/%lld\n", fz / g, fm / g);
	}
	return 0;
}
