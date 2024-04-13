#include <bits/stdc++.h>
using namespace std;
#define MAXR 101
#define MAXK 5000

bool dp[MAXR][MAXK] = {false};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, k, reg1, reg2;
  while (cin >> r >> k) {
    vector<int> regions(r + 1, 0);
    for (int i = 1; i <= k; i++) {
      cin >> reg1 >> reg2;
      regions[reg1]++;
      regions[reg2]++;
    }

    for (int i = 0; i <= r; i++)
      dp[i][0] = true;
    for (int j = 1; j <= k; j++)
      dp[0][j] = false;

    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= k; j++) {
        if (regions[i - 1] > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - regions[i - 1]];
      }
    }

    if (dp[r][k])
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
}