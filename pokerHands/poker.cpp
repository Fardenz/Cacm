
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
    for (map<char, int>::iterator it = vb.begin(); it != vb.end(); ++it)
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
        valueW[white[i].at(0)];
        valueB[black[i].at(0)];

        suitW[white[i].at(1)];
        suitB[black[i].at(1)];
    }

    /*  int res = straightFlush(suitW, valueW, suitB, valueW);
    if (res > -1)
    {
    } */
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
