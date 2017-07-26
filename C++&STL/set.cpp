#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;//string集合

int main()
{
    string s,buf;
    while(cin>>s){
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        stringstream ss(s);
        while(ss>>buf)  
            dict.insert(buf);//set集合会自动从小到大排好，使用for循环即可遍历元素
    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();++it)
        cout<<*it<<endl;
    return 0;
}