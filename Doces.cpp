#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    while(cin >> M >> N && M && N)
    {
        int aux;
        vector<vector<int>> doces(M);
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> aux;
                doces[i].push_back(aux);
            }
        }
        for(int i = 0; i < M; i++)
        {
            for(int j = 1; j < N; j++)
            {
                if(j == 1)
                    doces[i][j] = max(doces[i][j - 1], doces[i][j]);
                else
                    doces[i][j] = max(doces[i][j - 1], doces[i][j - 2] + doces[i][j]);
            }
        }
        if(M == 1)
            cout << doces[0][N - 1] << endl;
        else if(M == 2)
            cout << max(doces[0][N - 1], doces[1][N - 1]) << endl;
        else
        {
            for(int i = 1; i < M; i++)
            {
                if(i == 1)
                    doces[i][N - 1] = max(doces[i - 1][N - 1], doces[i][N - 1]);
                else
                    doces[i][N - 1] = max(doces[i - 1][N - 1], doces[i - 2][N - 1] + doces[i][N - 1]);
            }
            cout << doces[M - 1][N - 1] << endl;
        }
    }
}