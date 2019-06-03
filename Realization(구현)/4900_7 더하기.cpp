#include <bits/stdc++.h>
using namespace std;
string code[10] = { "063", "010", "093", "079", "106",
"103", "119", "011", "127", "107"};

int main()
{
    while(true)
    {
        ios_base :: sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        string s,A,B;
        cin >>s;
        if(s=="BYE") break;
        for(int i=0;i<s.size();i++)
            if(s[i]=='+')
            {
                A=s.substr(0,i);
                B=s.substr(i+1,s.size()-i-2);
            }
        string tmp1,tmp2;
        for(int i=0;i<A.size();i++)
        {
            if(i%3!=0) continue;
            int n;
            for(int j=0;j<10;j++)
                if(code[j]==A.substr(i,3))
                    n=j;
            tmp1+=to_string(n);
        }
        for(int i=0;i<B.size();i++)
        {
            if(i%3!=0) continue;
            int n;
            for(int j=0;j<10;j++)
                if(code[j]==B.substr(i,3))
                   n=j;
            tmp2+=to_string(n);
        }
        cout <<s;
        string sum=to_string(stoi(tmp1)+stoi(tmp2));
        for(int i=0;i<sum.size();i++)
        {
            for(int j=0;j<10;j++)
                if(sum[i]-'0'==j)
                cout <<code[j];
        }
        cout <<"\n";
    }
}
