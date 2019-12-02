#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <complex>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 987654321;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef complex<double> base;

void fft(vector <base> &a, bool invert)
{
	int n = sz(a);
	for (int i = 1, j = 0; i<n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * M_PI / len*(invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; j++) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (int i = 0; i<n; i++) a[i] /= n;
	}
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res)
{
	vector <base> fa(all(a)), fb(all(b));
	int n = 1;
	while (n < max(sz(a), sz(b))) n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for (int i = 0; i<n; i++) fa[i] *= fb[i];
	fft(fa, true);
	res.resize(n);
	for (int i = 0; i<n; i++) res[i] = int(fa[i].real() + (fa[i].real()>0 ? 0.5 : -0.5));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	vector<int>a, b, ans;
	cin >> N;
	a.resize(2 * N), b.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		a[i + N] = a[i];
	}
	for (int i = 0; i < N; i++)cin >> b[N - i - 1];
	multiply(a, b, ans);
	int maxN = -INF;
	for (int i = N; i < 2 * N; i++)maxN = max(maxN, ans[i]);
	cout << maxN;
}