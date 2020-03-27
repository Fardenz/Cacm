#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct piece
{
    int left, right, cost;
};

static struct piece dp[53][53];
int positions[1005];

int solveCase(int l, int n)
{
    // restart data structure
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j].cost = INT16_MAX / 2;
            dp[i][j].left = -1;
            dp[i][j].right = -1;
        }
    }

    // set secondary diagonal values to 0
    for (int i = 0; i < n - 1; i++)
    {
        int row = n - 2 - i;
        int col = i;

        dp[row][col].cost = 0;
        dp[row][col].left = positions[i];
        dp[row][col].right = positions[i + 1];
    }

    //calculate costs
    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = n - 3 - i; j >= 0; j--)
        {
            int row = n - 2 - j;
            int col = j + 1;

            while (row >= i)
            {
                int cost = dp[i][col].cost + dp[row][j].cost + dp[i][col].right - dp[row][j].left;

                if (cost < dp[i][j].cost)
                {
                    dp[i][j].cost = cost;
                    dp[i][j].left = dp[row][j].left;
                    dp[i][j].right = dp[i][col].right;
                }
                row--;
                col++;
            }
        }
    }
    return dp[0][0].cost;
}

int main(int argc, char const *argv[])
{
    int l, n;

    scanf("%d", &l);
    while (l != 0)
    {

        scanf("%d", &n);
        positions[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &positions[i]);
        }

        positions[n + 1] = l;

        int res = solveCase(l, n + 2);
        printf("The minimum cutting is %d.\n", res);

        scanf("%d", &l);
    }
    return 0;
}
