#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int dp[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  while (cin >> n >> m >> k && n && m && k) {
    vector<pair<pair<int, int>, int>> apples(k + 1);
    for (int i = 1; i <= k; i++) {
      cin >> apples[i].first.first >> apples[i].first.second >>
          apples[i].second;
      dp[i] = 0;
    }

    cin >> apples[0].first.first >> apples[0].first.second;
    apples[0].second = 0;
    dp[0] = 0;

    for (int i = 0; i <= k; i++)
      dp[i] = 0;

    for (int i = k; i >= 0; i--) {
      int xNow = apples[i].first.first, yNow = apples[i].first.second,
          timeNow = apples[i].second;
      for (int j = k; j > i; j--) {
        int xAfter = apples[j].first.first, yAfter = apples[j].first.second,
            dist = apples[j].second - timeNow;
        if (abs(xNow - xAfter) <= dist && abs(yNow - yAfter) <= dist && dist)
          dp[i] = max(dp[i], dp[j]);
      }
      if (i)
        dp[i]++;
    }

    cout << dp[0] << endl;
  }
}