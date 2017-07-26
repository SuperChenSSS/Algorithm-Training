//思路：把每个单词标准化，即全部转化为小写字母后再进行排序，然后再放到map中进行统计
#include<iostream>
#include<string>
//#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string,int> cnt;
vector<string>  words;

//将单词s进行“标准化”
string repr(const string& s){
    string ans = s;
    for(int i=0;i<ans.length();i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n = 0;
    string s;
    while(cin>>s){
        if(s[0]=='#')
            break;
        words.push_back(s);
        string r = repr(s);
        if(!cnt.count(r))    
            cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i=0;i<words.size();i++)
        if(cnt[repr(words[i])]==1)
            ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}