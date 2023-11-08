#include <bits/stdc++.h>
using namespace std;

pair<int, int> arestas[1000000], pesos[1000000];
int chefe[1001], grau[1001];

void UFinit(int numVertices)
{
    for(int i = 1; i <= numVertices; i++)
    {
        chefe[i] = i;
        grau[i] = 1;
    }
}

int UFfind(int vertice)
{
    int ans = vertice;
    while(ans != chefe[ans])
        ans = chefe[ans];
    return ans;
}

void UFunion(int x, int y)
{
    if(grau[x] < grau[y])
    {
        chefe[x] = y;
        grau[y] += grau[x];
    }
    else
    {
        chefe[y] = x;
        grau[x] += grau[y];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numArestas, numVertices = 0;
    cin >> numArestas;
    for(int i = 0; i < numArestas; i++)
    {
        cin >> arestas[i].first >> arestas[i].second >> pesos[i].first;
        if(arestas[i].first > numVertices || arestas[i].second > numVertices)
            numVertices = max(arestas[i].first, arestas[i].second);
        pesos[i].second = i;
    }
    sort(pesos, pesos + numArestas);
    UFinit(numVertices);
    int x, y, z, cont = 1, ans = 0;
    for(int i = numArestas - 1; i >= 0 && cont < numVertices; i--)
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
    cout << ans << endl;
    UFinit(numVertices);
    cont = 1;
    ans = 0;
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
    cout << ans << endl;
}