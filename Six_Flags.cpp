#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, cont = 1;
    int dp[601] = {0};
    while(cin >> n >> t && n)
    {
        vector<pair<int,int>> brinquedos(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> brinquedos[i].first >> brinquedos[i].second;
        for(int i = 0; i <= t; i++)
            dp[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= t; j++)
            {
                if(j >= brinquedos[i].first)
                    dp[j] = max(dp[j], dp[j - brinquedos[i].first] + brinquedos[i].second);
            }
        }
        cout << "Instancia " << cont++ << endl << dp[t] << endl << endl;
    }
}