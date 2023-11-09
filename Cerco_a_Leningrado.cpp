#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int soldiers[1001], dist[1001], visitado[1001];

int dijkstra(vector<vector<int>> &adj, int origem, int destino)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;
    bool flag = false;
    dist[origem] = soldiers[origem];
    fila.push({dist[origem], origem});
    while(!fila.empty() && !flag)
    {
        int vertex = fila.top().second;
        fila.pop();
        if(vertex == destino)
            flag = true;
        if(!visitado[vertex] && !flag)
        {
            visitado[vertex] = true;
            for(int i = 0; i < adj[vertex].size(); i++)
            {
                int dest = adj[vertex][i];
                if(!visitado[dest] && dist[dest] > dist[vertex] + soldiers[dest])
                {
                    dist[dest] = dist[vertex] + soldiers[dest];
                    fila.push({dist[dest], dest});
                }
            }
        }
    }
    return dist[destino];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, ans;
    double prob;
    while(cin >> n >> m >> k >> prob)
    {
        int aux1, aux2;
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < m; i++)
        {
            cin >> aux1 >> aux2;
            adj[aux1].push_back(aux2);
            adj[aux2].push_back(aux1);
        }
        for(int i = 1; i <= n; i++)
        {
            soldiers[i] = 0;
            dist[i] = INF;
            visitado[i] = false;
        }
        cin >> aux1;
        for(int i = 0; i < aux1; i++)
        {
            cin >> aux2;
            soldiers[aux2]++;
        }
        cin >> aux1 >> aux2;
        ans = dijkstra(adj, aux1, aux2);
        if(ans > k)
            printf("0.000\n");
        else
            printf("%.3f\n", pow(prob, ans));
    }
}