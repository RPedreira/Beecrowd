#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXK 10

int m[MAXN + 1][MAXK + 1], d[MAXN + 1][MAXK + 1], p[MAXN + 1], pannels[MAXN + 1];

void partition(int n, int k){
    int cost;
    int i,j,x;
    p[0] = 0;
    for (i = 1; i <= n; i++)
        p[i] = p[i - 1] + pannels[i];
    for (i = 1; i <= n; i++)
        m[i][1] = p[i];
    for (j = 1; j <= k; j++)
        m[1][j] = pannels[1];
    for (i = 2; i <= n; i++){
        for (j = 2; j <= k; j++){
            m[i][j] = INT_MAX;
            for (x = 1; x <= (i - 1); x++){
                cost = max(m[x][j - 1], p[i] - p[x]);
                if (m[i][j] > cost) {
                    m[i][j] = cost;
                    d[i][j] = x;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nPannels, trucks, freight;
    cin >> n;
    while(n--){
        cin >> nPannels >> trucks >> freight;
        for(int i = 1; i <= nPannels; i++)
            cin >> pannels[i];
        partition(nPannels, trucks);
        cout << m[nPannels][trucks] << " $" << (m[nPannels][trucks] * freight) * trucks << endl;
    }
}