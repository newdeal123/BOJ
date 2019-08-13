#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int cache[101][101],cnt=0;
map<string,int> mp;
string key[101];
vector<int>v1,v2;

int f(int idx1,int idx2)
{
    if(idx1==v1.size()||idx2==v2.size()) return 0;
    int&ret=cache[idx1][idx2];
    if(ret!=-1)return ret;
    if(v1[idx1]==v2[idx2]) return ret=f(idx1+1,idx2+1)+1;
    else return ret=max(f(idx1+1,idx2),f(idx1,idx2+1));

}

void output(int idx1,int idx2)
{
    if(idx1==v1.size()||idx2==v2.size()) return ;
    if(v1[idx1]==v2[idx2])
    {
        cout<<key[v1[idx1]]<<" ";
        return output(idx1+1,idx2+1);
    }
    int ret1=f(idx1+1,idx2),ret2=f(idx1,idx2+1);
    if(ret1>=ret2) return output(idx1+1,idx2);
    else return output(idx1,idx2+1);
}

int main()
{
    while(true)
    {
    memset(cache,-1,sizeof(cache));
    cnt=0;
    mp.clear(),v1.clear(),v2.clear();
    bool first=true;
    while(true)
    {
        string s;
        getline(cin,s);
        if(s=="")return 0;
        if(s=="#"&&!first) break;
        if(s=="#"){first=false; continue;}
        vector<int>v;
        int idx=0;
        for(int i=0;i<s.size();i++)
            if(s[i]==' '||i==s.size()-1)
            {
                string tmp=s.substr(idx,i-idx);
                if(i==s.size()-1)tmp=s.substr(idx,i-idx+1);
                if(mp.find(tmp)==mp.end()) {mp.insert(make_pair(tmp,cnt));key[cnt++]=tmp;}
                v.push_back(mp[tmp]);
                idx=i+1;
            }
        if(first)for(auto i:v)v1.push_back(i);
        else for(auto i:v)v2.push_back(i);
    }

    output(0,0);
    cout<<"\n";
    }
}
