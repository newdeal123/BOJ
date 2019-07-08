#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100+2;

int n, board[MAX_N][MAX_N];

int main()
{
    cin>>n;

    if (n == 2)
    {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i < n ; ++i)
        board[1][i] = i;

    board[1][n] = n * (n - 1) / 2;

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        board[i][j] = board[i - 1][j] + board[1][n];


    for (int i = 1; i <= n; ++i)
        {
            board[n][i] = n * board[n - 1][i];
            for (int j = 1; j < n; ++j)
                board[n][i] -= board[j][i];
        }


    for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cout<<board[i][j]<<" ";
            cout<<"\n";
        }

  return 0;
}
