#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF=987654321;
int N,M,R,K,buyTicketCost=0,noneCost=0;
map<string,int> mp;
int dist[101][101];
vector<int>course;

struct CITY
{
    int u,v,cost;
    string train;
};
vector<CITY>city;

int getCost(CITY v)
{
    if(v.train=="Mugunghwa" || v.train=="ITX-Cheongchun" || v.train=="ITX-Saemaeul" )return 0;
    else if(v.train=="S-Train"||v.train=="V-Train") return (int)((double)v.cost/2.0);
    else return v.cost;
}

void initialization()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
    {
        if(i==j)dist[i][j]=0;
        else dist[i][j]=INF;
    }

}

int floyd()
{
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>R;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        mp.insert(make_pair(s,i));
    }
    cin>>M;
    while(M--)
    {
        string s;
        cin>>s;
        course.push_back(mp[s]);
    }
    cin>>K;
    initialization();
    while(K--)
    {
        string a,b,c;
        int d;
        cin>>a>>b>>c>>d;
        city.push_back({mp[b],mp[c],d,a});
        dist[mp[b]][mp[c]]=min(dist[mp[b]][mp[c]],d);
        dist[mp[c]][mp[b]]=min(dist[mp[c]][mp[b]],d);
    }
    floyd();
    for(int i=1;i<course.size();i++)
        noneCost+=dist[course[i-1]][course[i]];

    initialization();
    for(auto i:city)
        {
            dist[i.u][i.v]=min(dist[i.u][i.v],getCost(i));
            dist[i.v][i.u]=min(dist[i.v][i.u],getCost(i));
        }
    floyd();
    buyTicketCost+=R;
    for(int i=1;i<course.size();i++)
        buyTicketCost+=dist[course[i-1]][course[i]];

    if(buyTicketCost<noneCost)cout<<"Yes";
    else cout<<"No";
}

