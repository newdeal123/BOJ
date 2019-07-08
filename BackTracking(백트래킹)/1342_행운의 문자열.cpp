#include <bits/stdc++.h>
using namespace std;
string s,myS;
int arrSum['z'-'a'+1]={0, };

bool canUse(int idx)
{
    for(int i=0;i<idx;i++)
        if(myS[i]==myS[i+1]) return false;
    return true;
}

int dfs(int idx)
{
    if(idx==s.size())
        return 1;
    int sum=0;
    for(char i='a';i<='z';i++)
    {
        if(!arrSum[i-'a']) continue;
        myS[idx]=i;
        if(canUse(idx))
        {
            arrSum[i-'a']--;
            sum+=dfs(idx+1);
            arrSum[i-'a']++;
        }
    }
    return sum;
}

int main()
{
    cin>>s;
    myS.resize(s.size());
    for(auto i:s)
        arrSum[i-'a']++;
    cout << dfs(0);

}
