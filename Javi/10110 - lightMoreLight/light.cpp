
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool is_perfect_square(long n)
{
    if (n < 0)
        return false;
    long root(round(sqrt(n)));
    return n == root * root;
}

int main(int argc, char const *argv[])
{
    long cross;
    int count, x, n;
    string s;
    getline(cin, s);
    cross = stol(s);

    while (cross != 0)
    {
        cout << (is_perfect_square(cross) ? "yes" : "no") << '\n';
        getline(cin, s);
        cross = stol(s);
    }
    return 0;
}
