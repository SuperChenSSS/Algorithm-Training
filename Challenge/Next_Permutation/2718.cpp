#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
int l,r,T,length;
char temp[100];
string a,b,L,R;
long long abase10,bbase10;
long long lowsum,lowlength,highsum,highlength,sum;

string trans(int x,int y, string s)
{
    string res = "";
    int sum = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum = sum * x + s[i] - '0';
        }
        else
        {
            sum = sum * x + s[i] - 'A' + 10;
        }
    }
    while(sum)
    {
        char tmp = sum % y;
        sum /= y;
        if(tmp <= 9)
        {
            tmp += '0';
        }
        else
        {
            tmp = tmp - 10 + 'A';
        }
        res = tmp + res;
    }
    if(res.length()==0) res = '0';
    return res;
}

int main()
{
    freopen("1007.txt","r",stdin);
    scanf("%d",&T);
    //cout<<atoi(trans(10,5,(string)tmp).c_str());
    while(T--)
    {
        sum = 0;
        cin>>L>>R;
        scanf("%d%d",&l,&r);
        for(int i = l; i<=r; ++i)
        {
            lowsum = 0;
            highsum = 0;
            a = trans(10,i,L);
            b = trans(10,i,R);
            lowlength = length = a.length();
            for(int j = 0; j<=length/2+1; ++j)
            {
                temp[j] = a[j];
            }
            if(length&1)
            {
                temp[length/2+1] = '\0';
            }
            else
            {
                temp[length/2] = '\0';
            }
            a = trans(i,10,temp);
            cout<<" "<<a<<" ";
            
            
            highlength = length = b.length();
            for(int j = 0; j<=length/2+1; ++j)
            {
                temp[j] = b[j];
            }
            if(length&1)
            {
                temp[length/2+1] = '\0';
            }
            else
            {
                temp[length/2] = '\0';
            }
            b = trans(i,10,temp);
            cout<<" "<<b<<" ";
            //cout<<a<<" "<<b<<" "<<endl;
            abase10 = atoi(a.c_str());
            bbase10 = atoi(b.c_str());
            printf("bBase:  %d   \n",bbase10);
            
            length = a.length();
            for(int j = 2;j<=lowlength;++j)
            {
                lowsum+=(i-1)*pow(i,(j-2)/2);
            }
            lowsum+=abase10 - pow(i,length-1)+1;
            printf("Lowsum:%d\n",lowsum);
            
            length = b.length();
            
            for(int j = 2;j<=highlength;++j)
            {
                highsum+=(i-1)*pow(i,(j-2)/2);
            }
            highsum+=bbase10 - pow(i,length-1)+1;
            printf("Highsum:%d\n\n",highsum);
            //printf("bBase:  %d  POW:%d I:%d\n",bbase10,(int)pow(i,length-1),i);
            
            for(int p = 0;p < lowlength/2;++p)
            {
                if(L[p] != L[lowlength-p])
                {
                    lowsum-=1;
                    break;
                }
            }
            for(int p = 0;p < highlength/2;++p)
            {
                if(R[p] != R[highlength-p])
                {
                    highsum-=1;
                    break;
                }
            }
            sum += (highsum - lowsum + 1)*(i-1)+atoi(R.c_str())-atoi(L.c_str())+1;
            
            
        }
        printf("%d\n",sum);
    }
}
