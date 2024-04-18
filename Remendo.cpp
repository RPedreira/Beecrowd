#include <bits/stdc++.h>
using namespace std;

int dp[1001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c, t1, t2;
  while (cin >> n >> c >> t1 >> t2) {
    vector<int> holes(n + 1, -1);

    for (int i = 1; i <= n; i++) {
      cin >> holes[i];
      dp[i] = INT_MAX;
    }

    for (int i = 1; i <= n; i++) {
      int indexFloor1, indexFloor2;
      indexFloor1 = lower_bound(holes.begin() + 1, holes.end(), holes[i] - t1) -
                    (holes.begin() + 1);
      indexFloor2 = lower_bound(holes.begin() + 1, holes.end(), holes[i] - t2) -
                    (holes.begin() + 1);
      if (indexFloor1 == n)
        dp[i] = min(dp[i], dp[0] + t1);
      else
        dp[i] = min(dp[i], dp[indexFloor1] + t1);
      if (indexFloor2 == n)
        dp[i] = min(dp[i], dp[0] + t2);
      else
        dp[i] = min(dp[i], dp[indexFloor2] + t2);
    }

    cout << dp[n] << endl;
  }
}