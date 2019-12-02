#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, T;
vector<int>arr,tmp,ans;

bool isPossible(int mid)
{
    int ret = 0;
    tmp=arr;

    for (int i = 0;i < N - 1;i++)
    {
        if (tmp[i] + mid < tmp[i + 1])
        {
            ret += tmp[i + 1] - tmp[i] - mid;
            tmp[i + 1] = tmp[i] + mid;
        }
    }

    for (int i = N - 1;i > 0;i--)
    {
        if (tmp[i] + mid < tmp[i - 1])
        {
            ret += tmp[i - 1] - tmp[i] - mid;
            tmp[i - 1] = tmp[i] + mid;
        }
    }
    return ret <= T;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>T;
    arr.resize(N),tmp.resize(N);
    for (int i=0;i<N;i++)cin>>arr[i];

    int left = 0, right = (int)1e9 + 1;
    while (left <= right)
        {

            int mid = (left + right)/2;

            if (isPossible(mid))
                {
                    ans=tmp;
                    right = mid - 1;
                }
            else left = mid + 1;
        }


    for (auto i:ans) cout<<i<<" ";


}

