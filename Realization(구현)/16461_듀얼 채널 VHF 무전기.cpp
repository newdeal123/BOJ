#include<bits/stdc++.h>
using namespace std;
const int MIN=144000,MAX=146000;
int ch1,ch2;

int getNum(int type,int fin)
{
    int ans=6,cnt=0,tmp;
    tmp=ch1,cnt=0;
    while(tmp!=fin)
    {
        tmp-=20;
        if(ans<cnt)break;
        if(tmp<MIN)tmp=MAX;
        cnt++;
    }
    ans=min(ans,cnt+(type!=1));
    tmp=ch1,cnt=0;
    while(tmp!=fin)
    {
        tmp+=20;
        if(ans<cnt)break;
        if(tmp>MAX)tmp=MIN;
        cnt++;
    }
    ans=min(ans,cnt+(type!=1));


    tmp=ch2,cnt=0;
    while(tmp!=fin)
    {
        tmp-=20;
        if(ans<cnt)break;
        if(tmp<MIN)tmp=MAX;
        cnt++;
    }
    ans=min(ans,cnt+(type!=2));

     tmp=ch2,cnt=0;
    while(tmp!=fin)
    {
        tmp+=20;
        if(ans<cnt)break;
        if(tmp>MAX)tmp=MIN;
        cnt++;
    }
    ans=min(ans,cnt+(type!=2));

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2,s;
        cin>>s1>>s2;
        ch1=stoi(s1.substr(0,3)+s1.substr(4,3));
        ch2=stoi(s2.substr(0,3)+s2.substr(4,3));
        char c;
        cin>>c>>s;
        cout<<getNum(c-'A'+1,stoi(s.substr(0,3)+s.substr(4,3)))<<"\n";

    }
}
