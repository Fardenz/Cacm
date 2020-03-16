#include <stdio.h>
#include <algorithm> // std::sort
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Adyacente
{
public:
    int dest, coste;
    Adyacente(int dest, int coste)
    {
        this->dest = dest;
        this->coste = coste;
    }
};
class Grafo
{
public:
    int numNodos, numAristas;
    std ::vector<int> gradosEntrada;
    std ::vector<std ::vector<Adyacente>> adyacentes;
    Grafo(int numNodos)
    {
        this->numNodos = numNodos;
        this->numAristas = 0;
        gradosEntrada.resize(numNodos, 0);
        adyacentes.resize(numNodos);
    }

    void
    insertarArista(int origen, int dest, int coste)
    {
        Adyacente ady(dest, coste);
        adyacentes[origen].push_back(ady);
        gradosEntrada[dest]++;
        numAristas++;
    }
    int getArista(int origen, int dest)
    {
        for (auto ady : adyacentes[origen])
        {
            if (ady.dest == dest)
            {
                return ady.coste;
            }
        }
        return 0;
    }

    bool existeArista(int origen, int dest)
    {
        for (auto ady : adyacentes[origen])
        {
            if (ady.dest == dest)
            {
                return true;
            }
        }
        return false;
    }
    void eliminarArista(int origen, int dest)
    {
        for (unsigned int i = 0; i < adyacentes[origen].size(); i++)
        {
            Adyacente ady = adyacentes[origen][i];
            if (ady.dest == dest)
            {
                adyacentes[origen].erase(adyacentes[origen].begin() + i);
                gradosEntrada[origen]--;
                numAristas--;
            }
        }
    }

    std ::string toString()
    {
        std ::stringstream res;
        for (int i = 0; i < numNodos; i++)
        {
            res << " Vertice : " << i;
            std ::vector<Adyacente> l = adyacentes[i];
            if (l.empty())
            {
                res << " sin adyacentes ";
            }
            else
            {
                res << " con adyacentes : ";
            }
            for (auto ady : l)
            {
                res << ady.dest << "(" << ady.coste << ") ";
            }
            res << "\n";
        }
        return res.str();
    }
};

bool check(std ::vector<int> recheck, std ::vector<std ::vector<Adyacente>> adyacentes, std ::vector<int> colour)
{
    bool res = true;
    std ::vector<int> next;

    for (auto nodeToRecheck : recheck)
    {
        int val = 0;
        for (auto ady : adyacentes[nodeToRecheck])
        {

            if (val == 0)
            {
                val = colour[ady.dest];

                switch (val)
                {
                case 0:
                    recheck.push_back(nodeToRecheck);
                    break;
                case 1:
                    val = -1;
                    break;
                case -1:
                    val = 1;
                    break;
                }
                colour[nodeToRecheck] = val;
            }
            else
            {
                if (colour[nodeToRecheck] == colour[ady.dest])
                {
                    res = false;
                }
            }
        }
    }
    return res;
}

void solveCase(Grafo g)
{
    bool res = true;
    int nodos = g.numNodos;
    std ::vector<std ::vector<Adyacente>> adyacentes = g.adyacentes;
    std ::vector<int> recheck(nodos);

    std ::vector<int> colour(nodos);
    // 0 non colored
    colour[0] = 1;

    for (int i = 0; i < nodos && res; i++)
    {
        int val = 0;

        switch (colour[i])
        {
        case 0:
            recheck.push_back(i);
            break;
        case 1:
            val = -1;
            break;
        case -1:
            val = 1;
            break;
        }

        if (colour[i] != 0)
        {
            for (auto ady : adyacentes[i])
            {
                if (colour[ady.dest] == 0 || colour[ady.dest] == val)
                {
                    colour[ady.dest] = val;
                }
                else
                {
                    res = false;
                }
            }
        }
    }
    if (res)
    {
        res = check(recheck, adyacentes, colour);
    }

    if (res)
    {
        //print success

        std::cout << "BICOLORABLE." << '\n';
    }
    else
    {
        //print failure
        std::cout << "NOT BICOLORABLE." << '\n';
    }
}

int main(int argc, char const *argv[])
{
    char linia[120];
    int n, i, r, p, l, n1, n2;
    int P[1000];
    scanf(" %d", &n);
    while (n != 0)
    {
        Grafo g = Grafo(n);
        scanf(" %d", &l);
        for (i = 0; i < l; i++)
        {
            scanf(" %d %d", &n1, &n2);
            g.insertarArista(n1, n2, 1);
        }

        //int size = sizeof(P) / sizeof(P[0]);
        solveCase(g);
        scanf(" %d", &n);
    }
    //printf("\n");

    return 0;
}
