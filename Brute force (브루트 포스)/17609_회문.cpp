#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int t,N;
string s;

bool is_palindrome()
{
    int left=0,right=N-1;
    while(left<=right)
    {
        if(s[left++]!=s[right--])return false;
    }
    return true;
}

bool can_palindrome(int left,int right,bool flag)
{
    if(left>right)return true;
    if(s[left]==s[right])return can_palindrome(left+1,right-1,flag);
    else if(flag) return max(can_palindrome(left+1,right,false),can_palindrome(left,right-1,false));
    else return false;
}

int getAns()
{
    if(is_palindrome())return 0;
    else if(can_palindrome(0,N-1,1)) return 1;
    else return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>s;
        N=s.size();
        cout<<getAns()<<"\n";
    }

}
