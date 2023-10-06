#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int dp[51][101];
    while(t--)
    {
        int n, c, r;
        cin >> n;
        vector<pair<int,int>> balas(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> balas[i].first >> balas[i].second;
        cin >> c >> r;
        for(int i = 0; i <= n; i++)
            dp[i][0];
        for(int i = 0; i <= c; i++)
            dp[0][i];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(balas[i].second <= j)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - balas[i].second] + balas[i].first);
            }
        }
        if(dp[n][c] >= r)
            cout << "Missao completada com sucesso" << endl;
        else
            cout << "Falha na missao" << endl;
    }
}