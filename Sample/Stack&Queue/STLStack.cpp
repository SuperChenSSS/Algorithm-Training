#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
    s.push(10);
    s.push(5);
    int n = s.size();
    if(!s.empty())
        printf("Not empty!");
    for(int i=0;i<n;i++)
    {
        int d = s.top();
        printf("%d ",d);
        s.pop();
    }
    printf("\n");
    return 0;
}