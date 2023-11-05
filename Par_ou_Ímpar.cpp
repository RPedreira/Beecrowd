#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n)
    {
        int aux;
        vector<int> cartoes;
        cartoes.push_back(0);
        for(int i = 0; i < 2 * n; i++)
        {
            cin >> aux;
            cartoes.push_back(aux);
        }
        for(int i = 0; i <= 2 * n; i++)
            dp[i] = 0;
        int turn = 1;
        while(turn < 2 * n)
        {
            for(int i = 1; i + turn <= 2 * n; i++)
            {
                if(turn % 2)
                {
                    if(cartoes[i] % 2 == 0 && cartoes[i + turn] % 2 == 0)
                        dp[i] = max(dp[i], dp[i + 1]) + 1;
                    else if(cartoes[i] % 2 == 0)
                        dp[i] = max(dp[i], dp[i + 1] + 1);
                    else if(cartoes[i + turn] % 2 == 0)
                        dp[i] = max(dp[i] + 1, dp[i + 1]);
                    else
                        dp[i] = max(dp[i], dp[i + 1]);
                }
                else
                    dp[i] = min(dp[i], dp[i + 1]);
            }
            turn++;
        }
        cout << dp[1] << endl;
    }
}