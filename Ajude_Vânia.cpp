#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, cont = 1, dp[1001][101] = {0};
    while(cin >> n >> c && n && c)
    {
        vector<pair<int,int>> livros(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> livros[i].first >> livros[i].second;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j >= livros[i].first)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - livros[i].first] + livros[i].second);
            }
        }
        cout << "Caso " << cont++ << ": " << dp[n][c] << endl;
    }
}