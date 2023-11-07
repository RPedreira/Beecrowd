#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string c1, c2;
    while(cin >> c1 >> c2)
    {
        cout << "To get from " << c1 << " to " << c2 << " takes ";
        int linhaIni, linhaFim, colunaIni, colunaFim;
        linhaIni = c1[1] - '1';
        linhaFim = c2[1] - '1';
        colunaIni = c1[0] - 'a';
        colunaFim = c2[0] - 'a';
        bool visitado[8][8] = {false}, found = false;
        queue<pair<pair<int,int>, int>> BFS;
        BFS.push({{linhaIni,colunaIni}, 0});
        while(!BFS.empty() && !found)
        {
            int linha, coluna, moves;
            linha = BFS.front().first.first;
            coluna = BFS.front().first.second;
            moves = BFS.front().second;
            visitado[linha][coluna] = true;
            BFS.pop();
            if(coluna == colunaFim && linha == linhaFim)
            {
                cout << moves;
                found = true;
            }
            else if(!found)
            {
                if(coluna > 1 && linha > 0 && !visitado[linha - 1][coluna - 2])
                {
                    BFS.push({{linha - 1, coluna - 2}, moves + 1});
                    visitado[linha - 1][coluna - 2] = true;
                }
                if(coluna > 1 && linha < 7 && !visitado[linha + 1][coluna - 2])
                {
                    BFS.push({{linha + 1, coluna - 2}, moves + 1});
                    visitado[linha + 1][coluna - 2] = true;
                }
                if(coluna > 0 && linha > 1 && !visitado[linha - 2][coluna - 1])
                {
                    BFS.push({{linha - 2, coluna - 1}, moves + 1});
                    visitado[linha - 2][coluna - 1] = true;
                }
                if(coluna > 0 && linha < 6 && !visitado[linha + 2][coluna - 1])
                {
                    BFS.push({{linha + 2, coluna - 1}, moves + 1});
                    visitado[linha + 2][coluna - 1] = true;
                }
                if(coluna < 7 && linha > 1 && !visitado[linha - 2][coluna + 1])
                {
                    BFS.push({{linha - 2, coluna + 1}, moves + 1});
                    visitado[linha - 2][coluna + 1] = true;
                }
                if(coluna < 7 && linha < 6 && !visitado[linha + 2][coluna + 1])
                {
                    BFS.push({{linha + 2, coluna + 1}, moves + 1});
                    visitado[linha + 2][coluna + 1] = true;
                }
                if(coluna < 6 && linha > 0 && !visitado[linha - 1][coluna + 2])
                {
                    BFS.push({{linha - 1, coluna + 2}, moves + 1});
                    visitado[linha - 1][coluna + 2] = true;
                }
                if(coluna < 6 && linha < 7 && !visitado[linha + 1][coluna + 2])
                {
                    BFS.push({{linha + 1, coluna + 2}, moves + 1});
                    visitado[linha + 1][coluna + 2] = true;
                }
            }
        }
        cout << " knight moves.\n";
    }
}