#include <bits/stdc++.h>
using namespace std;

int n;

struct node{
    int norte, sul, leste, oeste, visitado;
};

node mapa[10][10];

int bfs(int x, int y, int xDest, int yDest)
{
    queue<pair<pair<int,int>, int>> fila;
    fila.push({{x,y}, 0});
    while(!fila.empty())
    {
        int xAtual = fila.front().first.first, yAtual = fila.front().first.second, distancia = fila.front().second;
        fila.pop();
        mapa[n - 1 - yAtual][xAtual].visitado = 1;
        if(xAtual == xDest && yAtual == yDest)
            return distancia;
        if(mapa[n - 1 - yAtual][xAtual].norte && !mapa[n - 1 - yAtual - 1][xAtual].visitado)
            fila.push({{xAtual, yAtual + 1}, distancia + 1});
        if(mapa[n - 1 - yAtual][xAtual].sul && !mapa[n - 1 - yAtual + 1][xAtual].visitado)
            fila.push({{xAtual, yAtual - 1}, distancia + 1});
        if(mapa[n - 1 - yAtual][xAtual].oeste && !mapa[n - 1 - yAtual][xAtual - 1].visitado)
            fila.push({{xAtual - 1, yAtual}, distancia + 1});
        if(mapa[n - 1 - yAtual][xAtual].leste && !mapa[n - 1 - yAtual][xAtual + 1].visitado)
            fila.push({{xAtual + 1, yAtual}, distancia + 1});
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, x, y, xDest, yDest, ans;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> mapa[i][j].norte >> mapa[i][j].sul >> mapa[i][j].oeste >> mapa[i][j].leste;
                mapa[i][j].visitado = 0;
            }
        }
        cin >> p;
        for(int i = 0; i < p; i++)
        {
            cin >> x >> y >> xDest >> yDest;
            ans = bfs(x, y, xDest, yDest);
            if(ans == -1)
                cout << "Impossible\n";
            else
                cout << ans << endl;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    mapa[i][j].visitado = 0;
        }
        cout << endl;
    }
}