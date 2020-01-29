#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int n,a,b,dA[4]={1,-1,1,-1},dB[4]={-1,1,1,-1};

struct NODE {
	int a, b, jump;
};
queue<NODE> q;

bool is_in_range(int A,int B)
{
    if(A<1||A>n||B<1||B>n)return false;
    return true;
}

int BFS()
{
    q.push({ a,b,0 });
	while (!q.empty())
    {
		NODE now = q.front();
		if (now.a == now.b) return now.jump;
		q.pop();
		for(int i=0;i<4;i++)
        {
            int jump = 1<<now.jump;
            int dist=abs(now.a-now.b);
            NODE next={now.a+dA[i]*jump,now.b+dB[i]*jump,now.jump+1};
            if(!is_in_range(next.a,next.b))continue;
            if(dist%(jump*4)==0 && i>1) q.push(next);
            else if(dist%(jump*4)!=0 && i<=1) q.push(next);
        }

	}
	return -1;
}


int main()
{
	cin>>n>>a>>b;
	if (abs(a - b) % 2) cout<<-1;
	else cout<<BFS();
}
