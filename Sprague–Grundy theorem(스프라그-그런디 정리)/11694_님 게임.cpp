#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,k=0;
    bool allOne=true;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        k^=tmp;
        if(tmp>1)allOne=false;
    }
    if(!allOne)cout<<(k>0?"koosaga":"cubelover");
    else cout<<(k>0?"cubelover":"koosaga");
}
