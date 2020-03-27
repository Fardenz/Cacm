#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Element
{
public:
    int accumulatedCost, next;
    Element(int a, int n) : accumulatedCost(a), next(n)
    {
    }
    Element()
    {
    }
};

void solveCase()
{
}

int main(int argc, char const *argv[])
{
    int r, c;

    while (scanf("%d%d", &r, &c) == 2)
    {

        vector<int> cols(c);
        vector<vector<int>> matrix(r, cols);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                scanf("%d", &matrix[i][j]);
            }
        }

        vector<Element> elements(c);
        vector<vector<Element>> dp(r, elements);

        for (int i = 0; i < r; i++)
        {
            dp[i][c - 1].accumulatedCost = matrix[i][c - 1];
            dp[i][c - 1].next = i;
        }

        for (int i = c - 1; i > 0; i--)
        {
            for (int j = 0; j < r; j++)
            {
                dp[j][i - 1].accumulatedCost = INT16_MAX;
            }

            for (int j = 0; j < r; j++)
            {
                int row_upper = (j - 1 + r) % r;
                int row_horiz = j;
                int row_lower = (j + 1) % r;

                int cost_upper = dp[j][i].accumulatedCost + matrix[row_upper][i - 1];
                int cost_horiz = dp[j][i].accumulatedCost + matrix[row_horiz][i - 1];
                int cost_lower = dp[j][i].accumulatedCost + matrix[row_lower][i - 1];

                if (cost_horiz < dp[row_horiz][i - 1].accumulatedCost)
                {
                    dp[row_horiz][i - 1].accumulatedCost = cost_horiz;
                    dp[row_horiz][i - 1].next = j;
                }

                if (cost_upper < dp[row_upper][i - 1].accumulatedCost)
                {
                    dp[row_upper][i - 1].accumulatedCost = cost_upper;
                    dp[row_upper][i - 1].next = j;
                }

                if (cost_lower < dp[row_lower][i - 1].accumulatedCost)
                {
                    dp[row_lower][i - 1].accumulatedCost = cost_lower;
                    dp[row_lower][i - 1].next = j;
                }
            }
        }

        int best_row = 0;
        for (int i = 1; i < r; i++)
        {
            if (dp[i][0].accumulatedCost < dp[best_row][0].accumulatedCost)
            {
                best_row = i;
            }
        }

        //res

        int row = best_row;

        printf("%d", row + 1);

        for (int i = 1; i < c; i++)
        {
            row = dp[row][i - 1].next;
            printf(" %d", row + 1);
        }

        printf("\n%d\n", dp[best_row][0].accumulatedCost);
    }
    return 0;
}
