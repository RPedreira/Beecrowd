#include <bits/stdc++.h>
using namespace std;
#define MAX 102

vector<pair<int, int>> v(MAX);
int dp[MAX][MAX][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, instance = 1;
  cin >> t;
  while (t--) {
    int n, d, going = 0, returning = 0, ans = 0;
    char aux;

    cin >> n >> d;
    v[0] = {0, 1};
    v[n + 1] = {d, 1};

    for (int i = 1; i <= n; i++) {
      cin >> aux >> v[i].first;

      v[i].first *= -1;
      if (aux == 'B')
        v[i].second = 1;
      else
        v[i].second = 0;
    }

    for (int i = 1; i <= n + 1; i++) {
      if (v[i].second) {
        ans = max(ans, max(v[i].first - going, v[i].first - returning));
        going = returning = v[i].first;
      } else if (going > returning) {
        ans = max(ans, v[i].first - returning);
        returning = v[i].first;
      } else {
        ans = max(ans, v[i].first - going);
        going = v[i].first;
      }
    }

    cout << "Case " << instance++ << ": " << ans << endl;
  }
}