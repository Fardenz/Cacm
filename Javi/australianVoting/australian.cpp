#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

const std::vector<std::string> explode(const std::string &s, const char &c)
{
    std::string buff{""};
    std::vector<std::string> v;

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

bool doesntContain(std::vector<int> candidatesToErase, int val)
{

    bool res = true;

    for (int j = 0; j < candidatesToErase.size(); j++)
    {
        if (candidatesToErase[j] == val)
        {
            return false;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{

    //scanf("%d", &t);
    int numCasos;
    char line[120];

    scanf(" %d", &numCasos);
    fgets(line, 120, stdin);

    while (--numCasos >= 0)
    {
        std::string candidates[25];
        int t, i, candidatesNumber;
        std::vector<std::vector<int>> vote(1000);
        int m = 0;

        std::vector<bool> activeCandidates(25, true);
        scanf(" %d", &candidatesNumber);
        fgets(line, 120, stdin);

        for (i = 1; i <= candidatesNumber; i++)
        {
            //line = null;
            fgets(line, 81, stdin);

            //scanf(" %s", &line);
            // std::string candidates[i](line);

            candidates[i] = line;
        }

        //scan ballots
        std::string lin;
        std::stringstream sin;
        std::string delimiter = " ";

        while (std::getline(std::cin, lin))
        {
            if (lin == "")
                break;
            std::vector<std::string> v{explode(lin, ' ')};

            for (int i = 0; i < v.size(); i++)
            {
                vote[m].push_back(std::stoi(v[i]));
            }

            m++;
        }

        /*
  *
  * SOLVE CASE
  * 
  */
        std::string winner = "";

        while (winner == "")
        {
            std::vector<int> candidatesToErase;
            std::vector<int> candidatesVotes(25, 0);
            int validVotes = m;
            for (int i = 0; i < m; i++)
            {

                for (int j = 0; j < vote.size(); j++)
                {
                    int v = vote[i][j];
                    if (activeCandidates[v])
                    {
                        candidatesVotes[v]++;
                        break;
                    }
                }
            }

            int min = 9999;

            for (i = 1; i <= candidatesNumber; i++)
            {
                if (activeCandidates[i])
                {
                    int val = candidatesVotes[i];
                    if (val > validVotes / 2)
                    {
                        // cout winner is candidates[i]
                        winner = candidates[i];
                    }
                    else
                    {
                        if (val < min)
                        {
                            min = val;
                            candidatesToErase.clear();
                        }
                        if (val == min)
                        {
                            candidatesToErase.push_back(i);
                        }
                    }
                }
            }

            // no winner yet, we need to discard the loser/losers
            bool isTie = true;
            if (candidatesToErase.size() > 1)
            {

                //check if it is tie
                for (int i = 1; i <= candidatesNumber; i++)
                {
                    if (activeCandidates[i] == true && doesntContain(candidatesToErase, i))
                    {
                        isTie = false;
                    }
                }
            }
            else
            {
                isTie = false;
            }

            for (int i = 0; i < candidatesToErase.size(); i++)
            {
                int loserVote = candidatesToErase[i];

                if (isTie)
                {
                    winner += candidates[loserVote];
                }
                else
                {
                    activeCandidates[loserVote] = false;
                }
            }
        }
        std::cout << winner + (numCasos != 0 ? "\n" : "");
    }
    return 0;
}
