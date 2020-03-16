
#include <iostream>
#include <vector>
#include <string>
#include <map>

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
bool straightFlush(std::map<char, int> sw, std::map<char, int> vw, std::map<char, int> sb, std::map<char, int> vb)
{

    bool canBew = false, canBeb = false;
    bool isw = false, isb = false;

    std::map<char, int>::iterator it = sw.begin();
    // Iterate over the map using c++11 range based for loop
    for (std::pair<char, int> element : sw)
    {
        // Accessing KEY from element
        char key = element.first;
        // Accessing VALUE from element.
        int val = element.second;

        if (val == 5)
        {
            canBew = true;
        }
    }

    it = sb.begin();
    for (std::pair<char, int> element : sb)
    {
        char key = element.first;
        int val = element.second;

        if (val == 5)
        {
            canBeb = true;
        }
    }

    if (!canBew && !canBeb)
        return -1;

    //checkw

    it = vw.begin();
    int last = -1, first = -1;
    for (std::pair<char, int> element : vw)
    {
        char key = element.first;
        int val = element.second;

        if (val != 1)
            break;

        if (last == -1)
        {
            first = key;
            last = key;
        }
        else
        {
            if (key != last + 1)
                break;
            else
                last++;
        }
    }
    if (last - first == 5)
    {
        isw = true;
    }

    //if cant be b return
    //checkb
}
/*bool fourOfKind(std::map<char, int> sw, std::map<char, int> vw, std::map<char, int> sb, std::map<char, int> vb)
{
    bool white = false, black = false;

    //white
    for (map<char, int>::iterator it = vw.begin(); it != vw.end(); ++it)
    {
    char key = it->first;
        if(vw[key]>)
    
        }

    //black
for (map<char, int>::iterator it = vb.begin(); it != vb.end(); +ºQA<    A   q   AAAAa   º   +it)
    {
    }

    if (black && white)
    {
    }
}*/
bool straightFlush2(std::map<char, int> sw, std::map<char, int> vw, std::map<char, int> sb, std::map<char, int> vb)
{
}
int getWinner(vector<string> white, vector<string> black)
{
    std::map<char, int> suitW;
    std::map<char, int> valueW;
    std::map<char, int> suitB;
    std::map<char, int> valueB;

    for (int i = 0; i < 5; i++)
    {
        valueW[white[i].at(0)]++;
        valueB[black[i].at(0)]++;

        suitW[white[i].at(1)]++;
        suitB[black[i].at(1)]++;
    }

    int res = straightFlush(suitW, valueW, suitB, valueW);
    if (res > -1)
    {
        return res;
    }
}

void processCase(vector<string> game)
{

    vector<string> white, black;

    for (int i = 0; i < 5; i++)
    {
        string s = game.back();
        game.pop_back();
        white.push_back(s);
    }
    black = game;

    int res = getWinner(white, black);
    switch (res)
    {
    case 2: // black
        /* code */
        break;
    case 0: //tie
        /* code */
        break;
    case 1: //white
        /* code */
        break;
    }
}

int main(int argc, char const *argv[])
{
    int count, x, n;
    string s;
    getline(cin, s);

    while (cin)
    {
        vector<string> cards = split(s, ' ');

        processCase(cards);

        getline(cin, s);
    }
    return 0;
}
