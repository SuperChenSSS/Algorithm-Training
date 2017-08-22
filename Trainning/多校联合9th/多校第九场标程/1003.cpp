#include<bits/stdc++.h>

using namespace std;
const int N = 11000;
const double eps = 1e-10;
const double pi = acos(-1.0);
typedef complex<double> Point;

double Det(const Point & a, const Point & b) {return (conj(a) * b).imag();}
double Dot(const Point & a, const Point & b) {return (conj(a) * b).real();}
int sgn(double x) {if(fabs(x) < eps) return 0; if(x > eps) return 1; return -1;}

double _ang;
Point ori = (Point) {0, 0};
struct Line :public vector<Point>{
	double k;
	Line(){}
	Line(Point a, Point b){
		push_back(a), push_back(b);
		k = atan2((b - a).imag(), (b - a).real());
	}
};
Point Vec(Line a) {return a[1] - a[0];}
Point LineIntersection(const Line & a, const Line & b){
	double k1 = Det(Vec(a), Vec(b));
	double k2 = Det(Vec(b), a[0] - b[0]);
	if(!sgn(k1)){
		if(sgn(abs(a[1] - b[0]) - abs(a[0] - b[0])) > 0) return a[0];
		else return a[1];
	}
	return a[0] + Vec(a) * k2 / k1;
}

bool operator < (const Line & a, const Line & b){
	Line cur = (Line) {ori, (Point) {cos(_ang), sin(_ang)}};
	if(sgn(abs(LineIntersection(a, cur)) - abs(LineIntersection(b, cur))) < 0) return 1;
	return 0;
}

struct Event{
	double k;
	int id, typ;
	bool operator < (const Event & a) const{
		if(sgn(k - a.k)) return k < a.k;
		return typ < a.typ;
	}
};

double CalcAng(const Point & a) {return atan2(a.imag(), a.real());}
Point p[N];
Line w[N], seg[N];
Event e[N << 3];

int q, n, m, tot;
set<Line> s;
int rec[N];

int Calc(int x){
	tot = 0;
	s.clear();
	for(int i = 1; i <= n; i ++)
		e[++ tot] = (Event){CalcAng(p[i] - p[x]), i, 1};
	
	bool flag = 0;
	for(int i = 1; i <= m; i++){
		seg[i] = (Line) {w[i][0] - p[x], w[i][1] - p[x]};
		if(sgn(CalcAng(seg[i][0]) - CalcAng(seg[i][1])) > 0) swap(seg[i][0], seg[i][1]);
		flag = 1;
		if(sgn(Det(Vec(seg[i]), Point(-1, 0))) != 0 && sgn(abs(CalcAng(seg[i][0]) - CalcAng(seg[i][1])) - pi) > 0) flag = 0;
		if(flag) e[++ tot] = (Event) {CalcAng(seg[i][0]), i, 0}, e[++tot] = (Event) {CalcAng(seg[i][1]), i, 2};
		else{
			e[++ tot] = (Event) {-pi, i, 0};
			e[++ tot] = (Event) {CalcAng(seg[i][0]), i, 2};
			e[++ tot] = (Event) {CalcAng(seg[i][1]), i, 0};
			e[++ tot] = (Event) {pi, i, 2};
		}
	}
	
	sort(e + 1, e + tot + 1);
	int cnt = 0;
	Point dir, dd;
	Line t;
	for(int i = 1; i <= tot; i ++){
		_ang = e[i].k;
		if(e[i].typ & 1){
			dir = (Point) {cos(_ang), sin(_ang)};
			if(s.empty() || sgn(abs(LineIntersection(*s.begin(), (Line) {ori, dir})) - abs(p[e[i].id] - p[x])) > 0){
				cnt ++, rec[cnt] = e[i].id;
			}
		}
		else if(!e[i].typ) s.insert(seg[e[i].id]);
		else s.erase(seg[e[i].id]);
	}
	
	return cnt;
}

int Tcase;

char fi[100] = "pcx.in", fo[100] = "pcx.ans";
void Solve(){
	printf("Case #%d:\n", ++ Tcase);
	double x, y;
	Point a, b;
	for(int i = 1; i <= n; i ++){
		scanf("%lf%lf", &x, &y);
		p[i] = (Point) {x, y};
	}
	for(int i = 1; i <= m; i ++){
		scanf("%lf%lf", &x, &y);
		a = (Point) {x, y};
		scanf("%lf%lf", &x, &y);
		b = (Point) {x, y};
		w[i] = (Line) {a, b};
	} 
	
	int ans;
	for(int i = 1; i <= q; i ++){
		scanf("%lf%lf", &x, &y);
		p[n + 1] = (Point) {x, y};
		ans = Calc(n + 1);
		printf("%d\n", ans);
	}
	
	return;
}

int main(){
	freopen("_pc.in", "r", stdin);
	freopen("_pc.ans", "w", stdout);
	while(~scanf("%d%d%d", &n, &m, &q))
		Solve();	
	//printf("--->%lf\n", (double) clock() / CLOCKS_PER_SEC);
	return 0;
}
