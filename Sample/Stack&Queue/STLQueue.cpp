#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
    q.push(10);
    q.push(5);
    int n = q.size();
    for(int i=0;i<n;i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
    return 0;
}