#include<iostream>
#include<string>
using namespace std;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};

struct Union{
    int boy,girl;
    Union(int boy=0,int girl=0):boy(boy),girl(girl){};
}U1;

Point operator + (const Point& A,const Point& B){
    return Point(A.x+B.x,A.y+B.y);
}
//把类型由标准型转到Point类型
ostream& operator << (ostream &out,const Point& p){
    out<<"("<<p.x<<","<<p.y<<")";
    return out;
}

int main()
{
    Point a(2,4),b(1,2);
    a.x = 3;
    cout<<a+b<<"\n";
    return 0;
}