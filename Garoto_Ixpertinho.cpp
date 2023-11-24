#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

pair<int, int> arestas[MAX];
pair<double, int> pesos[MAX];
int chefe[MAX], grau[MAX];
int numVertices, numArestas, descansos;
double distMax;

void UFinit(int numVertices)
{
    descansos = 0;
    for(int i = 0; i <= numVertices; i++)
    {
        chefe[i] = i;
        grau[i] = 0;
    }
}

int UFfind(int vertice)
{
    if(vertice == chefe[vertice])
        return vertice;
    else
        return chefe[vertice] = UFfind(chefe[vertice]);
}

void UFunion(int x, int y)
{
    if (grau[x] > grau[y])
        chefe[y] = x;
    else
    {
        chefe[x] = y;
        if (grau[x] == grau[y])
            grau[y]++;
    }
}

double MSTKruskal()
{
    int x, y, z, cont = 1;
    double ans = 0;
    sort(pesos, pesos + numArestas);
    for(int i = 0; i < numArestas && cont < numVertices; i++)
    {
        z = pesos[i].second;
        x = UFfind(arestas[z].first);
        y = UFfind(arestas[z].second);
        if(x != y)
        {
            ans += pesos[i].first;
            cont++;
            if(pesos[i].first > distMax)
                descansos++;
            UFunion(x, y);
        }
    }
    return ans;
}

int main(){
    while(true)
    {
        int aux;
        double ans;
        scanf("%d%d%lf", &numVertices, &numArestas, &distMax);
        if(numVertices == 0)
            break;
        UFinit(numVertices);
        for(int i = 0; i < numArestas; i++)
        {
            scanf("%d%d%lf", &arestas[i].first, &arestas[i].second, &pesos[i].first);
            if(pesos[i].first > distMax)
                pesos[i].first += 2;
            pesos[i].second = i;
        }
        ans = MSTKruskal();
        printf("%.2lf %d\n", ans, descansos);
    }
}