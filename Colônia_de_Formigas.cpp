#include <bits/stdc++.h>
using namespace std;

int pai[100000] = {0};
long long int dist[100000] = {0};

int lowestCommonAncestor(int origem, int destino)
{
    vector<int> pathOrigem;
    bool flag = false;
    if(origem == destino)
        flag = true;
    while(origem != 0 && !flag)
    {
        origem = pai[origem];
        pathOrigem.push_back(origem);
        if(origem == destino)
            flag = true;
    }
    int i = 0;
    while(destino != 0 && !flag)
    {
        while(pathOrigem[i] > destino)
            i++;
        if(destino == pathOrigem[i])
            flag = true;
        else
            destino = pai[destino];
    }
    return destino;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, origem, destino;
    while(cin >> n && n)
    {
        for(int i = 1; i < n; i++)
        {
            cin >> pai[i] >> dist[i];
            dist[i] += dist[pai[i]];
        }
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cin >> origem >> destino;
            int LCA = lowestCommonAncestor(max(origem, destino), min(origem, destino));
            cout << (dist[origem] - dist[LCA]) + (dist[destino] - dist[LCA]);
            if(i < q - 1)
                cout << ' ';
        }
        cout << endl;
    }
}