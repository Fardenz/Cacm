#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <sstream>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>

using namespace std;

#define int64 long long

//not my own BigInt implementation, but I forgot where i got it from

class BigInt
{
public:
    const static int BASE = 1000000000;
    const static int BASE_WIDTH = 9;
    int len;
    int data[30];

    BigInt() : len(1)
    {
        data[0] = 0;
    }

    BigInt(const BigInt &v) : len(v.len)
    {
        memcpy(data, v.data, len * sizeof(int));
    }
    BigInt(int v) : len(0)
    {
        while (v > 0)
            data[len++] = v % BASE, v /= BASE;
    }
    BigInt &operator=(const BigInt &v)
    {
        len = v.len;
        memcpy(data, v.data, len * sizeof(int));
        return *this;
    }
    int &operator[](int i)
    {
        return data[i];
    }
    int operator[](int i) const
    {
        return data[i];
    }
    operator std::string()
    {
        std::stringstream ss;
        for (int i = len - 1; i >= 0; --i)
        {
            if (i < len - 1)
            {
                std::cout << std::setw(BASE_WIDTH) << std::setfill('0') << data[i];
            }
            else
            {
                std::cout << data[i];
            }
        }
        return ss.str();
    }
};

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt r;
    int i, carry = 0;
    for (i = 0; i < a.len || i < b.len || 0 < carry; ++i)
    {
        if (i < a.len)
            carry += a[i];
        if (i < b.len)
            carry += b[i];
        r[i] = carry % BigInt::BASE;
        carry /= BigInt::BASE;
    }
    r.len = i;
    return r;
}

vector<BigInt> results(10001);

int main(int argc, char const *argv[])
{

    int n = 1;
    BigInt aux = BigInt(1);
    results[0] = BigInt();

    for (int i = 1; i < 10001;)
    {

        for (int j = n; i < 10001 && j > 0; i++, j--)
        {
            results[i] = results[i - 1] + aux;
        }
        n++;
        aux = aux + aux;
    }

    while (cin >> n)
    {
        cout << (std::string)results[n] << '\n';
    }

    /*
    string s;

    getline(cin, s);

    while (cin)
    {

        try
        {
            n = stoi(s);

            cout << (std::string)results[n] << '\n';

            getline(cin, s);
        }
        catch (std::invalid_argument &e)
        {
            break;
        }
    }
    */
    return 0;
}
