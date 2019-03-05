#include <iostream>
using namespace std;
 
int cal(int num) 
{
    int sum = num;
    while (num!=0)
     {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 1000000; i++) 
    {
        if (cal(i) == n)
         { cout << i << '\n'; return 0; }
    }
    cout << 0 << '\n';
    return 0;
}
