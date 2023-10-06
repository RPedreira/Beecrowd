#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int dp[1000101];
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> blocos(n);
        for(int i = 0; i < m + 101; i++)
            dp[i] = i;
        for(int i = 0; i < n; i++)
            cin >> blocos[i];
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(i + blocos[j] <= m)
                    dp[i + blocos[j]] = min(dp[i + blocos[j]], dp[i] + 1);
            }
        }
        cout << dp[m] << endl;
    }
}