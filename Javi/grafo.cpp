#include <vector>
#include <sstream>

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