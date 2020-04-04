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

const vector<string> split(const string &s, const char &c)
{
    string buff{""};
    vector<string> v;

    for (auto n : s)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;
}
struct hole
{
    float x, y;
};

float getDistance(float x, float y, hole h)
{
    return sqrt(pow(h.x - x, 2) +
                pow(h.y - y, 2) * 1.0);
}

int main(int argc, char const *argv[])
{
    int h = 0;
    string s;
    float xd, yd, xg, yg;
    float distg, distd;

    getline(cin, s);

    while (cin)
    {
        try
        {
            vector<string> data = split(s, ' ');

            h = stoi(data[0]);

            xg = stof(data[1]);
            yg = stof(data[2]);

            xd = stof(data[3]);
            yd = stof(data[4]);

            vector<hole> holes;
            for (int i = 0; i < h; i++)
            {
                getline(cin, s);
                vector<string> data = split(s, ' ');
                hole h;
                h.x = stof(data[0]);
                h.y = stof(data[1]);

                holes.push_back(h);
            }
            bool haveResult = false;

            for (int i = 0; i < h; i++)
            {
                distg = getDistance(xg, yg, holes[i]);
                distd = getDistance(xd, yd, holes[i]);

                if (distg * 2 <= distd)
                {
                    printf("The gopher can escape through the hole at (%.3f", holes[i].x);
                    printf(",%.3f).\n", holes[i].y);
                    haveResult = true;

                    break;
                }
            }

            if (!haveResult)
            {
                cout << "The gopher cannot escape.\n";
            }

            getline(cin, s);
            getline(cin, s);
        }
        catch (std::invalid_argument &e)
        {
            break;
        }
    }

    return 0;
}
