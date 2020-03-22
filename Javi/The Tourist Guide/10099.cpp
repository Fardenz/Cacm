#include <stdio.h>
#include <algorithm> // std::sort
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

void solveCase(vector<vector<vector<int>>> g, int s, int d, int t)
{
    int amount = -1;
    int count = -1;
    long trips;

    for (int i = 1; i < g.size(); i++)
    {

        for (int j = 1; j < g.size(); j++)
        {

            for (int k = 1; k < g.size(); k++)
            {
                int p = g[i - 1][j][k];
                int n = min(g[i - 1][j][i], g[i - 1][i][k]);
                g[i][j][k] = max(n, p);
            }
        }
    }

    trips = ceil(((double)t) / ((double)(g[g.size() - 1][s][d] - 1)));

    std::cout << "Minimum Number of Trips = " << trips << '\n';
}

int main(int argc, char const *argv[])
{
    int n, i, r, p, l, n1, n2, s, d, t, scenario = 1;
    scanf(" %d %d", &n, &r);
    while (n != 0)
    {
        vector<int> nodes(n + 1, 0);
        vector<vector<int>> nodeList(n + 1, nodes);
        vector<vector<vector<int>>> g(n + 1, nodeList);

        for (i = 0; i < r; i++)
        {
            scanf(" %d %d %d", &n1, &n2, &p);
            g[0][n1][n2] = p;
            g[0][n2][n1] = p;
        }
        scanf(" %d %d %d", &s, &d, &t);
        std::cout << "Scenario #" << scenario << '\n';

        solveCase(g, s, d, t);

        std::cout << '\n';

        scenario++;
        //next
        scanf(" %d %d", &n, &r);
    }

    return 0;
}
