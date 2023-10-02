#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n)
    {
        vector<int> peso(n + 1, 0), valor(n + 1, 0);
        for(int i = 1; i <= n; i++)
            cin >> valor[i] >> peso[i];
        int tam;
        cin >> tam;
        int mochila[n + 1][tam + 1];
        memset(mochila, 0, sizeof(mochila));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= tam; j++)
            {
                mochila[i][j] = mochila[i - 1][j];
                if(peso[i] <= j)
                {
                    mochila[i][j] = max(mochila[i][j], mochila[i - 1][j - peso[i]] + valor[i]);
                }
            }
        }
        cout << mochila[n][tam] << endl;
    }
}