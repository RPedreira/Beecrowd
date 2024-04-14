#include <bits/stdc++.h>
using namespace std;

int mentos[1001], dp[1001][1001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, instance = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> mentos[i];
      dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int left = j - i + 1, right = j;
        if (mentos[left] == mentos[right]) {
          dp[i][j] = 1 + dp[i - 2][right - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][right], dp[i - 1][right - 1]);
        }
      }
    }

    cout << "Caso #" << instance++ << ": " << dp[n][n] << endl;
  }
}