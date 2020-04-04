#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const ll INF=(int)1e9+100;

struct Cow
{
    ll height, weight, strength;
};

ll cache[(1 << 20)];
int weight[(1 << 20)], height[(1 << 20)];


int main()
{
    int n, h;
    cin >> n >> h;
    Cow cows[n];
    for (int i = 0; i < n; i++) 
        cin >> cows[i].height >> cows[i].weight >> cows[i].strength;
    for (int i = 0; i < (1 << n); i++)
    {
        cache[i] = -INF;
        int w = 0, h = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) w += cows[j].weight;
            if (i & (1 << j)) h += cows[j].height;
        }
        weight[i] = w;
        height[i] = h;
    }
    ll ans = -1;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) continue;
            int idx = i | (1 << j);
            if (cache[i] == -INF) cache[i] = INF;
            
            ll a=min(cache[i] - cows[j].weight, cows[j].strength);
            ll b=min(cows[j].strength - weight[i], cache[i]);
            
            cache[idx] = max(cache[idx], max(a,b));
            if (height[idx] >= h) ans = max(ans, cache[idx]);
        }
    }
    if (ans == -1) cout << "Mark is too tall";
    else cout << ans;

}
