#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        int N;
        cin >> N;
        vector <ll> v(N);
        for (int i = 0; i < N; i++)
                 cin >> v[i];
        sort(v.begin(), v.end());
        if (v[0] != 1)
                 cout << 1;
        else
        {
                 ll sum = 1; 
                 for (int i = 1; i < N; i++)
                 {
                         if (v[i] > sum + 1)break;
                         sum += v[i];
                 }
                 cout << sum + 1 ;
        }
}