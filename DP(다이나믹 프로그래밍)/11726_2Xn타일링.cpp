// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

// 출력
// 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

#include <stdio.h>
#define mod 10007

int main(void) {
    int n;
    scanf("%d",&n);
    int dp[1010];
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-2] % mod) + (dp[i-1] % mod);
    }
    
    printf("%d\n", dp[n] % mod);
    return 0;
}
