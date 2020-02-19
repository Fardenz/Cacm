
#include <stdio.h>
#include <algorithm> // std::sort
#include <string>
#include <vector>

std::string algo2(int a, int b, int c, int d)
{
    //algo 2
    //2*t(A)+t(B)+t(C)+t(D)
    // start
    std::string out = "";

    //cruzan a+d
    out += std::to_string(a) + " " + std::to_string(d) + '\n';

    // v a
    out += std::to_string(a) + '\n';

    // a+c
    out += std::to_string(a) + " " + std::to_string(c) + '\n';

    //v a
    out += std::to_string(a) + '\n';

    // semi-start
    return out;
}

std::string algo3(int a, int b, int c)
{

    //algo 3
    // start
    std::string out = "";

    // c a+c
    out += std::to_string(a) + " " + std::to_string(c) + '\n';

    //v a
    out += std::to_string(a) + '\n';

    // semi-start
    return out;
}

std::string algo1(int a, int b, int c, int d)
{
    //algo 1
    //t(A)+3*t(B)+t(D)
    std::string out = "";
    //start
    // cruzan a+b
    out += std::to_string(a) + " " + std::to_string(b) + '\n';
    //vuelve a
    out += std::to_string(a) + '\n';

    //c c+d
    out += std::to_string(c) + " " + std::to_string(d) + '\n';

    //v b
    out += std::to_string(b) + '\n';

    // semi- start
    return out;
}

void solveBridge(int p[], int n)
{
    int states, a, b, c, d, firstn = n;
    int cAlg1, cAlg2, totalCost = 0;
    std::string print = "";

    // Fix states calculations
    if (n % 2 == 0)
    {
        states = n / 2 - 1;
    }
    else
    {
        states = n / 2;
    }
    while (states > 0)
    {
        a = p[0];
        b = p[1];
        if (n - 2 != 1)
        {
            c = p[n - 2];

            d = p[n - 1];

            cAlg1 = a + 2 * b + d;
            cAlg2 = 2 * a + c + d;

            if (cAlg1 <= cAlg2)
            {
                //algo 1
                print += algo1(a, b, c, d);

                totalCost += cAlg1;
            }
            else
            {

                //algo 2
                print += algo2(a, b, c, d);
                totalCost += cAlg2;
            }
        }
        else
        {
            c = p[2];

            //algo 3
            print += algo3(a, b, c);
            totalCost += c + a;
        }

        n = n - 2;
        states--;
    }
    //solo quedan por cruzar a y b
    a = p[0];
    if (firstn > 1)
        b = p[1];
    else
        b = 0;

    if (b != 0)
    {
        totalCost += b;
        print += std::to_string(a) + " " + std::to_string(b) + '\n';
    }
    else
    {
        totalCost += a;
        print += std::to_string(a) + '\n';
    }

    //count print
    printf("%d\n", totalCost);
    printf("%s", print.c_str());
}

int main(int argc, char const *argv[])
{
    char linia[120];
    int numCasos, n, i;
    int P[1000];
    scanf(" %d", &numCasos);
    fgets(linia, 120, stdin);
    while (--numCasos >= 0)
    {
        scanf(" %d", &n);
        for (i = 0; i < n; i++)
            scanf(" %d", &P[i]);

        //int size = sizeof(P) / sizeof(P[0]);
        std::sort(P, P + n);

        solveBridge(P, n);
        if (numCasos != 0)
            printf("\n");
    }
    //printf("\n");

    return 0;
}
