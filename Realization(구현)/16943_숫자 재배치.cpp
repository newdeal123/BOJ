#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;

int main()
{
    string s;
    int n;
    cin >>s>>n;
    vector <int>v;
    for(auto i:s)
        v.push_back(i-'0');
    sort(v.begin(),v.end());
    int maxN=0;
    do
    {
        string tmp;
        for(auto i:v)
            tmp.push_back(i+'0');
        int c=stoi(tmp);
        if(c<=n && v[0]) maxN=max(maxN,c);
    }while(next_permutation(v.begin(),v.end()));
    if(!maxN)cout << -1;
    else cout <<maxN;
}
