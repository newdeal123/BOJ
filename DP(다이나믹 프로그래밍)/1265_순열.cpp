#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int N,K;
string cache[101][1<<13];

string add(string A, string B)
{
	string C(max(A.size(), B.size()), '0');
	bool carry = false;
	for (int i = 0; i<C.size(); i++) {
		int temp = carry;
		carry = false;
		if (i < A.size()) temp += A[A.size() - i - 1] - '0';
		if (i < B.size()) temp += B[B.size() - i - 1] - '0';
		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}
		C[C.size() - i - 1] = temp + '0';
	}
	if (carry) C.insert(C.begin(), '1');
	return C;
}

string f(int idx,int bits)
{
    if(idx==N)return "1";

    string&ret=cache[idx][bits];
    if(ret!="-1")return ret;
    ret="0";
    for(int i=0;i<2*K+1;i++)
    {
        if(bits&(1<<i))continue;
        int num=idx+K-i+1;
        if(num<=0||num>N)continue;
        int nextBits=bits|(1<<i);
        nextBits=(nextBits*2)%(int)(pow(2,2*K+1));
        ret=add(ret,f(idx+1,nextBits));
    }
    return ret;
}


int main()
{
    for(int i=0;i<101;i++)
        for(int j=0;j<(1<<13);j++)cache[i][j]="-1";
    cin>>N>>K;
    cout<<f(0,0);
}
