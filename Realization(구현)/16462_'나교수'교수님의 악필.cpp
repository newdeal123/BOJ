#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;

int main()
{
    int n,sum=0;
    vector<int>v;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
            if(s[i]=='0'||s[i]=='6'||s[i]=='9') s[i]='9';
        v.push_back(min(100,stoi(s)));
        sum+=min(100,stoi(s));
    }
    int average=(double)sum/(double)v.size()+0.5;
    cout<<average;

}
