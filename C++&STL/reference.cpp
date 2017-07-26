#include<iostream>
using namespace std;
void swap2(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a = 3,b = 4;
    swap2(a,b);
    cout<<a<<" "<<b<<"\n";
    return 0;
}