#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define EPSOL 0.000000001

double distancia(pair<int,int> x, pair<int,int> y)
{
    return sqrt((abs(x.first - y.first) * abs(x.first - y.first)) + (abs(x.second - y.second) * abs(x.second - y.second)));
}

pair<int,int> pos[101];
float dist[101][101], raio[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n)
    {
        int ops, antena1, antena2;
        for(int i = 1; i <= n; i++)
        {
            cin >> pos[i].first >> pos[i].second >> raio[i];
            dist[i][i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                double diff = distancia(pos[i], pos[j]);
                if(raio[i] >= diff || diff - raio[i] <= EPSOL)
                    dist[i][j] = diff;
                else
                    dist[i][j] = INF;
                if(raio[j] >= diff || diff - raio[j] <= EPSOL)
                    dist[j][i] = diff;
                else
                    dist[j][i] = INF;
            }
        }
        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        cin >> ops;
        for(int i = 0; i < ops; i++)
        {
            cin >> antena1 >> antena2;
            if(dist[antena1][antena2] == INF)
                cout << -1 << endl;
            else
                cout << (int)dist[antena1][antena2] << endl;
        }
    }
}