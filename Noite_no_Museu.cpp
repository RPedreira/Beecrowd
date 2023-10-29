#include <bits/stdc++.h>
using namespace std;
#define MAX_TIME 420

int dist[21][21], museus[21], n, maximoPossivel, ans;
bool visitados[21], flag;

void backflinstons(int museu, int sumTime, int maxMuseus){
    ans = max(ans, maxMuseus);
    if(ans == maximoPossivel)
        flag = true;
    if(!flag)
    {
        visitados[museu] = true;
        for(int i = 1; i <= n && !flag; i++)
        {
            if(!visitados[i] && sumTime + dist[museu][i] + museus[i] <= MAX_TIME)
                backflinstons(i, sumTime + dist[museu][i] + museus[i], maxMuseus + 1);
        }
        visitados[museu] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n && n)
    {
        ans = 0;
        flag = false;
        maximoPossivel = 0;
        int aux[20], soma = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> museus[i];
            aux[i - 1] = museus[i];
            if(museus[i] > MAX_TIME)
                visitados[i] = true;
            else
                visitados[i] = false;
        }
        sort(aux, aux + n);
        for(int i = 0; i < n; i++)
        {
            if(soma + aux[i] <= MAX_TIME)
            {
                maximoPossivel++;
                soma += aux[i];
            }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> dist[i][j];
        
        if(maximoPossivel > 0)
        {
            for(int i = 1; i <= n && !flag; i++)
            {
                if(!visitados[i])
                    backflinstons(i, museus[i], 1);
            }
        }
        cout << ans << endl;
    }
}