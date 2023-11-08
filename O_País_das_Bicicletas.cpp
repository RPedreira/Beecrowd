#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int altura[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, instancia = 1;
    while(cin >> m >> n && m && n)
    {
        int x, y, h, queries;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i == j)
                    altura[i][i] = 0;
                else
                {
                    altura[i][j] = INF;
                    altura[j][i] = INF;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y >> h;
            altura[x][y] = h;
            altura[y][x] = h;
        }
        for(int k = 1; k <= m; k++)
        {
            for(int i = 1; i <= m; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(altura[i][k] < altura[i][j] && altura[k][j] < altura[i][j])
                    {
                        altura[i][j] = max(altura[i][k], altura[k][j]);
                        altura[j][i] = altura[i][j];
                    }
                }
            }
        }
        cin >> queries;
        cout << "Instancia " << instancia++ << endl;
        for(int i = 0; i < queries; i++)
        {
            cin >> x >> y;
            if(x == y)
                cout << 0 << endl;
            else
                cout << altura[x][y] << endl;
        }
        cout << endl;
    }
}