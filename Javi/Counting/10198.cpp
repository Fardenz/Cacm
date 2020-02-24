

// Overflow Solution
//Not valid

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<long long> memo;

void solveCase(long n)
{
    if (n >= memo.size())
    {
        long long l;
        for (int i = memo.size(); i <= n; i++)
        {
            l = 2 * memo[i - 1] + memo[i - 2] + memo[i - 3];
            memo.push_back(l);
        }
    }

    //print result
    cout << memo[n] << '\n';
}

int main(int argc, char const *argv[])
{

    int n, i;
    int P[1000];
    string s;

    memo.reserve(1001);

    memo.push_back(0);
    memo.push_back(2);
    memo.push_back(5);
    memo.push_back(13);

    getline(cin, s);

    n = stoi(s);
    while (cin)
    {

        solveCase(n);
        getline(cin, s);
        n = stoi(s);
    }
    return 0;
}
