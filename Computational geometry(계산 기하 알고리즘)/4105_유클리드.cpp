#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <string.h>
#include <stack>
using namespace std;
const double PI = 2.0*acos(0.0);

struct vector2
{
	double x, y;
	explicit vector2(double x_, double y_) :x(x_), y(y_) {}
	bool operator == (const vector2& rhs) const {
		return (x == rhs.x && y == rhs.y);
	}
	bool operator < (const vector2& rhs) const {
		return (x != rhs.x ? x < rhs.x : y < rhs.y);
	}
	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator * (double rhs) const {
		return vector2(x*rhs, y*rhs);
	}

	//벡터의 길이를 반환한다.
	double norm() const{ return hypot(x,y); }
	//방향이 같은 단위 벡터를 반환한다.
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	//x축의 양의 방향으로부터 이 벡터까지의 반시계방향으로 잰 각도
	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
	//내적,외적의 구현
	double dot(const vector2& rhs) const {
		return  x*rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x*rhs.y - y*rhs.x;
	}
	//이 벡터를 rhs에 사영한 결과
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r*r.dot(*this);
	}

};

//++문제에 따라 추가해야 할 함수

//double형의 실수형 오류 방지
bool relativeEqual(double a, double b) {
	double diff = fabs(a - b);
	if (diff < 1e-10)return true;
	return diff <= 1e-8*max(fabs(a), fabs(b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed;
    cout.precision(3);
    while(true)
    {
        vector<vector2>v;
        bool fin=true;
        for(int i=0;i<6;i++)
        {
            double x,y;
            cin>>x>>y;
            if(x!=0||y!=0)fin=false;
            v.push_back(vector2(x,y));
        }
        if(fin)break;

        double area=abs((v[4]-v[3]).cross(v[5]-v[3]))/2.0;
        double k=area/abs((v[1]-v[0]).cross(v[2]-v[0]));
        vector2 H=v[0]+(v[2]-v[0])*k;
        vector2 G=H+(v[1]-v[0]);
        cout<<G.x<<" "<<G.y<<" "<<H.x<<" "<<H.y<<"\n";
    }
}
