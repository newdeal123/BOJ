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
//두 벡터의 사이각(세타)
double Interval(vector2 a, vector2 b) {
	return acos(a.dot(b) / a.norm()*b.norm());
}
int main()
{
    vector<vector2>v;
    for(int i=0;i<3;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(vector2(x,y));
    }
    sort(v.begin(),v.end());

    for(int i=0;i<3;i++)
    {
        vector<vector2>line;
        for(int j=0;j<3;j++)
            if(i!=j)line.push_back(v[j]-v[i]);
        //cout<<i<<": "<<Interval(line[0],line[1])<<endl;
        if(Interval(line[0],line[1])==PI/2.0)
        {
            vector2 ans=line[0]+line[1]+v[i];
            cout<<ans.x<<" "<<ans.y;
            return 0;
        }
    }
}
