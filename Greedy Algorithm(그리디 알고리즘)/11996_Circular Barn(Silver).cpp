#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> Barn[1001];
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin >>tmp;
        while(tmp--)
            Barn[i].push_back(0);
    }
    for(int i=1;i<=2;i++)
        for(int now=1;now<=n;now++)
        {
            if(Barn[now].size()<2) continue;
            //가장 거리가 큰 소만 두고 나머지는 옆으로 넘김.
            sort(Barn[now].rbegin(),Barn[now].rend());
            int nextIdx=now==n ? 1 : now+1;
            while(Barn[now].size()!=1)
            {
                Barn[nextIdx].push_back(Barn[now].back()+1);
                Barn[now].pop_back();
            }
        }
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=Barn[i][0]*Barn[i][0];
    cout << sum;
}
