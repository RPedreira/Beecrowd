#include <bits/stdc++.h>
using namespace std;
#define MAX_TIME 50
#define MAX 100001
#define MOD 1000000007

long long int pd[MAX_TIME][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, m, n;
    long long int ans = 0;
    cin >> t >> m >> n;
    for(int i = m; i <= n; i++)
    {
        pd[0][i] = 1;
        if(i == m || i == n)
            pd[1][i] = 1;
        else
            pd[1][i] = 2;
    }
    for(int i = 2; i < t; i++)
    {
        for(int j = m; j <= n; j++)
        {
            if(j == m)
                pd[i][j] = pd[i - 1][j + 1];
            else if(j == n)
                pd[i][j] = pd[i - 1][j - 1];
            else
                pd[i][j] = ((pd[i - 1][j - 1] % MOD) + (pd[i - 1][j + 1] % MOD)) % MOD;
        }
    }
    for(int i = m; i <= n; i++)
        ans = ((ans % MOD) + (pd[t - 1][i] % MOD)) % MOD;
    cout << ans << endl;
}