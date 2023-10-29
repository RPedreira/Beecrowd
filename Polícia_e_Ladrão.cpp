#include <bits/stdc++.h>
using namespace std;

int mapa[5][5];

bool busca(int linha, int coluna)
{
    bool ans = false;
    if(linha == 4 && coluna == 4)
        ans = true;
    mapa[linha][coluna] = 1;
    if(linha > 0 && !ans)
    {
        if(mapa[linha - 1][coluna] == 0)
            ans = ans || busca(linha - 1, coluna);
    }
    if(linha < 4 && !ans)
    {
        if(mapa[linha + 1][coluna] == 0)
            ans = ans || busca(linha + 1, coluna);
    }
    if(coluna > 0 && !ans)
    {
        if(mapa[linha][coluna - 1] == 0)
            ans = ans || busca(linha, coluna - 1);
    }
    if(coluna < 4 && !ans)
    {
        if(mapa[linha][coluna + 1] == 0)
            ans = ans || busca(linha, coluna + 1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        bool ans;
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                cin >> mapa[i][j];
        
        ans = busca(0, 0);

        if(ans)
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
    }
}