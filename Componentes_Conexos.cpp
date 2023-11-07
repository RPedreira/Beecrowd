#include <bits/stdc++.h>
using namespace std;

void DFS(int raiz, vector<vector<int>> &listAdj, vector<bool> &visitado, vector<int> &connected){
    visitado[raiz] = true;
    connected.push_back(raiz);
    for(auto x: listAdj[raiz])
    {
        if(!visitado[x])
            DFS(x, listAdj, visitado, connected);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, instance = 1;
    cin >> t;
    while(t--)
    {
        vector<vector<int>> graph(26);
        vector<bool> visitado(26, false);
        int v, e, components = 0;
        char aux1, aux2;
        cin >> v >> e;
        for(int i = 0; i < e; i++)
        {
            cin >> aux1 >> aux2;
            graph[aux1 - 'a'].push_back(aux2 - 'a');
            graph[aux2 - 'a'].push_back(aux1 - 'a');
        }
        cout << "Case #" << instance << ":\n";
        for(int i = 0; i < v; i++)
        {
            vector<int> connected;
            if(!visitado[i])
            {
                DFS(i, graph, visitado, connected);
                components++;
                sort(connected.begin(), connected.end());
                for(int i = 0; i < connected.size(); i++)
                    cout << (char)(connected[i] + 'a') << ',';
                cout << endl;
            }
        }
        cout << components << " connected components\n\n";
        instance++;
    }
}