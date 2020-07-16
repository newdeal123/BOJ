#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=100000;

int main()
{
    int N,k=0;
    cin>>N;
    while(N--)
    {
        int tmp;
        cin>>tmp;
        k^=tmp;
    }
    cout<<(k>0?"koosaga":"cubelover");
}
