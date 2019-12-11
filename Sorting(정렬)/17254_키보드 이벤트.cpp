#include <bits/stdc++.h>
using namespace std;

struct Keyboard
{
    int key,sec;
    char c;
};

bool compare(Keyboard& a,Keyboard &b)
{
    if(a.sec != b.sec)
        return a.sec <b.sec;
    return a.key<b.key;
}

int main()
{

    vector <Keyboard>v;
    int N,M;
    cin >>N >> M;
    while(M--)
    {
        int a,b;
        char c;
        cin >>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),compare);

    for(int i=0;i<v.size();i++)
        cout << v[i].c;
}
