#include <stdio.h>
#include <algorithm> // std::sort
#include <string>
#include <vector>

void solveCase()
{
}

int main(int argc, char const *argv[])
{
    int numCasos, n, i, r, p;

    long long res[17][17][17];
    res[1][1][1] = 1;
    for (n = 2; n <= 13; n++)
    {
        for (p = 1; p <= n; p++)
        {
            for (r = 1; r <= n; r++)
            {
                res[n][p][r] = res[n - 1][p][r] * (n - 2) + res[n - 1][p - 1][r] + res[n - 1][p][r - 1];
            }
        }
    }

    scanf(" %d", &numCasos);
    while (--numCasos >= 0)
    {
        scanf(" %d %d %d", &n, &p, &r);
        printf("%lld\n", res[n][p][r]);
    }

    return 0;
}
