#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    list<int> m_list;
    vector<int> m_vector;
    m_vector.push_back(10);
    m_vector.push_back(8);
    m_vector.push_back(12);
    m_list.push_back(3);
    m_list.push_back(99);
    m_list.push_back(20);
    m_list.sort();
    //sort(m_vector.begin(),m_vector.end(),greater<int>());//倒序排列
    sort(m_vector.begin(),m_vector.end(),less<int>());//顺序排列
    list<int>::iterator it;
    for(it=m_list.begin();it!=m_list.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
    vector<int>::iterator iter;
    for(iter=m_vector.begin();iter!=m_vector.end();iter++)
        cout<<*iter<<" ";
    cout<<'\n';
    return 0;
}