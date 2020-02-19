
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int count, x, n;
    string s;
    getline(cin, s);

    while (cin)
    {
        if (s != "")
        {
            n = stoi(s);
            count = 0;
            x = n;
            while (x > 0)
            {
                while ((x % 10) == 1)
                {
                    count++;
                    x /= 10;
                }
                if (x > 0)
                    x += n;
            }
            cout << count << "\n";
        }
        getline(cin, s);
    }
    return 0;
}
