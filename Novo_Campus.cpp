#include <bits/stdc++.h>
using namespace std;
#define MAXV 1001
#define MAXA 500000

int numVertices, numArestas;

pair<int, int> arestas[MAXA], pesos[MAXA];
int chefe[MAXV], grau[MAXV];

void UFinit(int numVertices)
{
    for(int i = 1; i <= numVertices; i++)
    {
        chefe[i] = i;
        grau[i] = 0;
    }
}

int UFfind(int vertice)
{
    return (vertice == chefe[vertice]) ? vertice : chefe[vertice] = UFfind(chefe[vertice]);   
}

void UFunion(int x, int y)
{
    if(grau[x] < grau[y])
    {
        chefe[x] = y;
    }
    else
    {
        chefe[y] = x;
        if(grau[x] == grau[y])
            grau[x]++;
    }
}

int MSTKruskal()
{
    int x, y, z, cont = 1, ans = 0;
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
            UFunion(x, y);
        }
    }
    return (cont < numVertices) ? -1 : ans;
}

int main(){
    while(scanf("%d%d", &numVertices, &numArestas) != EOF)
    {
        for(int i = 0; i < numArestas; i++)
        {
            scanf("%d%d%d", &arestas[i].first, &arestas[i].second, &pesos[i].first);
            pesos[i].second = i;
        }
        if(numArestas < numVertices - 1)
            printf("impossivel\n");
        else
        {
            int ans;
            UFinit(numVertices);
            ans = MSTKruskal();
            if(ans == -1)
                printf("impossivel\n");
            else
                printf("%d\n", ans);
        }
    }
}