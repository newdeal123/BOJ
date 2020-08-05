#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool isSame(char a,char b)
{
    if(a>b)swap(a,b);
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

int main()
{
    int N;
    string s;
    cin>>N>>s;
    stack<pair<char,int>>stk;
    vector<bool>found(s.size(),false);
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(c=='('||c=='{'||c=='[') stk.push({c,i});
        else{
            if(!stk.empty()&&isSame(stk.top().first,c)){
                found[i]=found[stk.top().second]=true;
                stk.pop();
            }
        }
    }
    int cnt=0,ans=0;
    for(auto i:found)
    {
        if(i==true){
            cnt++;
            ans=max(ans,cnt);
        }
        else cnt=0;
    }
    ans=max(ans,cnt);
    cout<<ans<<"\n";

}
