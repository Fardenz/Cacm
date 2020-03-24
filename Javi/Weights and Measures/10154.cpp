#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Turtle
{
public:
    int weight, capacity;
    Turtle(int w, int c) : weight(w), capacity(c)
    {
    }

    bool operator<(const Turtle &other) const
    {
        return this->capacity < other.capacity || (this->capacity == other.capacity && this->weight > other.weight);
    }
};

void solveCase()
{
}

int main(int argc, char const *argv[])
{
    int capacity, weight, t = 0;

    vector<Turtle> turtles;

    while (scanf("%d%d", &weight, &capacity) == 2)
    {
        turtles.push_back(Turtle(weight, capacity));
        t++;
    }

    sort(turtles.begin(), turtles.begin() + t);

    vector<int> totalWeight(t + 1, INT16_MAX);
    totalWeight[0] = 0;

    int maxStack = 0;

    for (int i = 0; i < turtles.size(); i++)
    {
        for (int j = maxStack; j >= 0; j--)
        {

            int w = totalWeight[j] + turtles[i].weight;
            if (w <= turtles[i].capacity && w < totalWeight[j + 1])
            {
                totalWeight[j + 1] = w;
                maxStack = max(maxStack, j + 1);
            }
        }
    }
    printf("%d\n", maxStack);

    return 0;
}
