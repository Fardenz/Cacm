
#include <stdio.h>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    char linia[80];
    std::vector<std::string> words(1000);

    int c, numWords, i, n;
    int P[1000];
    scanf(" %d", &c);
    numWords = c;
    while (--c >= 0)
    {
        fgets(linia, 80, stdin);

        scanf(" %d", &n);
        for (i = 0; i < n; i++)
            scanf(" %d", &P[i]);
        /* Aqu´ı solucionar cada caso */
    }
    return 0;
}
