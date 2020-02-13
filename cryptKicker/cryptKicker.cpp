
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

#include <string>

using namespace std;
string controlString = "(NULL)";

//from http://www.cplusplus.com/articles/2wA0RXSz/
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
string transformToAsterisk(vector<string> words)
{

    string res = "";

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        for (int j = 0; j < word.length(); j++)
        {
            res += "*";
        }
        res += " ";
    }
    return res;
}
string canDecrypt(vector<string> words, map<char, char> dict)
{
    string res = "";

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        for (int j = 0; j < word.length(); j++)
        {
            if (dict[word.at(j)])
            {
                res += dict[word.at(j)];
            }
            else
            {
                return controlString;
            }
        }
        res += " ";
    }
    return res;
}

void processCase(string frase, map<int, vector<string>> possibleWords)
{
    vector<string> words = split(frase, ' ');

    map<char, char> dict;

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];

        for (int pw = 0; pw < possibleWords[word.length()].size();)
        {
            map<char, char> tempDict = dict;
            bool isWrong = false;

            string decWord = possibleWords[word.length()][pw];
            for (int j = 0; j < word.length(); j++)
            {
                if (!tempDict[word.at(j)])
                {
                    tempDict[word.at(j)] = decWord.at(j);
                }
                else
                {
                    if (tempDict[word.at(j)] != decWord.at(j))
                    {
                        //worng dict
                        isWrong = true;
                        tempDict = dict;
                        break;
                    }
                }
            }

            if (!isWrong)
            {
                //merge maps
                dict.insert(tempDict.begin(), tempDict.end());
                break;
            }
            else
            {
                pw++;
            }
        }
    }
    string res = canDecrypt(words, dict);
    if (res == controlString)
    {
        //cant decrypt
        res = transformToAsterisk(words);
    }
    cout << res << "\n";
}
int main(int argc, char const *argv[])
{
    char linia[100];
    map<int, vector<string>> possibleWords;
    string s;

    int c, numWords, i, n;
    int P[1000];
    scanf(" %d", &c);
    numWords = c;
    while (--c >= 0)
    {
        cin >> s;

        possibleWords[s.length()].push_back(s);
    }

    //get stdin till next \n
    getline(cin, s);

    //solve cases
    while (cin)
    {
        getline(cin, s);
        if (s != "")
            processCase(s, possibleWords);
    }

    return 0;
}
