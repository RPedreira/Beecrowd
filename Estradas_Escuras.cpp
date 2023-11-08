#include <bits/stdc++.h>
using namespace std;

pair<int, int> arestas[200000], pesos[200000];
int chefe[200000], grau[200000];

int UFfind(int v)
{
    int ans = v;
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

    int m, n;
    while(cin >> m >> n && m && n)
    {
        int x, y, z, cont = 1, ans = 0, total = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arestas[i].first >> arestas[i].second >> pesos[i].first;
            pesos[i].second = i;
            total += pesos[i].first;
        }
        for(int i = 0; i < m; i++)
        {
            chefe[i] = i;
            grau[i] = 1;
        }
        sort(pesos, pesos + n);
        for(int i = 0; i < n && cont < m; i++)
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
        cout << total - ans << endl;
    }
}