#include <stdio.h>
#include <stdlib.h>

using namespace std;

char candidates[20][81];

int votes[20][1000];

struct ballot
{
    int v1;
    int v2;
    int v3;
};

struct ballot ballots[1000];

int main()
{
    int t;
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++)
    {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            fgets(candidates[j], 81, stdin);
        }
        for (int v = 0;; v++)
        {
        }
    }
}
