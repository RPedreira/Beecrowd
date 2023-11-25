#include <bits/stdc++.h>
using namespace std;

bool visitado[10001];

bool dfs(vector<vector<int>> &graph, int atual, int pai)
{
    visitado[atual] = true;
    bool possivel = true;
    for(int i = 0; i < graph[atual].size() && possivel; i++)
    {
        if(graph[atual][i] != pai)
        {
            if(visitado[graph[atual][i]])
                possivel = false;
            else
                possivel = possivel && dfs(graph, graph[atual][i], atual);
        }
    }
    return possivel;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n >> m)
    {
        vector<vector<int>> graph(n + 1);
        bool possivel = true;
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if(a == b)
                possivel = false;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if(possivel)
        {
            for(int i = 1; i <= n; i++)
                visitado[i] = false;
            for(int i = 0; i < n; i++)
            {
                if(!visitado[i])
                    possivel = possivel && dfs(graph, i, 0);
            }
        }
        if(possivel)
            cout << "Seguro\n";
        else
            cout << "Inseguro\n";
    }
}