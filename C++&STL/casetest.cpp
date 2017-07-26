#include<iostream>
#include<string>
using namespace std;

int main()
{
    string ss = "Hello";
    //ss[2] = "3";
    bool isFind = ss.find("world");
    ss.replace(0,3,"oks");
    ss.append("World");
    cout<<ss<<endl;
    cout<<isFind<<endl;
    return 0;
}