#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
const int coeff[3] = {2,3,5};

int main()
{
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    set<ll> s;
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++)
    {
        ll x = pq.top();pq.pop();
        if(i == 1500)
        {
            cout<<"The 1500'th ugly number is "<<x<<".\n";
            break;
        }
        for(int j=0;j<3;j++)
        {
            ll x2 = x * coeff[j];
            if(!s.count(x2)){s.insert(x2);pq.push(x2);}
        }
    }
    return 0;
}