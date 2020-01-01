#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

bool compare(string a,string b)
{
    if(a==b)return false;
    string A=a+b,B=b+a;
    int len=a.size()+b.size();
    for(int i=0;i<len;i++)
        if(A[i]!=B[i])return A[i]>B[i];
}

int main()
{
    bool flag=false;
    int N;
    cin>>N;
    vector<string>v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
        if(v[i]!="0")flag=true;
    }
    if(!flag)
    {
        cout<<"0";
        return 0;
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v)cout<<i;

}
