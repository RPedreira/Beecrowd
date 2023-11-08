#include <bits/stdc++.h>
using namespace std;

bool visitado[401] = {false};

bool dfs(vector<vector<int>> &graph, int atual, int destino)
{
    bool flag = false;
    if(atual == destino)
        flag = true;
    else
    {
        visitado[atual] = true;
        for(int i = 0; i < graph[atual].size() && !flag; i++)
        {
            if(!visitado[graph[atual][i]])
                flag = flag | dfs(graph, graph[atual][i], destino);
        }
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p, aux1, aux2;
    cin >> n >> m >> p;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++)
    {
        cin >> aux1 >> aux2;
        graph[aux1].push_back(aux2);
        graph[aux2].push_back(aux1);
    }
    for(int i = 0; i < p; i++)
    {
        cin >> aux1 >> aux2;
        if(dfs(graph, aux1, aux2))
            cout << "Lets que lets\n";
        else
            cout << "Deu ruim\n";
        for(int i = 1; i <= n; i++)
            visitado[i] = false;
    }
}