#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int pipes, size;
    cin >> pipes >> size;
    vector<int> dp(size + 1, 0);
    for(int i = 0; i < pipes; i++)
    {
        int length, val;
        cin >> length >> val;
        for(int i = 1; i <= size; i++)
        {
            if(length <= i)
                dp[i] = max(dp[i], dp[i - length] + val);
        }
    }
    cout << dp[size] << endl;
}