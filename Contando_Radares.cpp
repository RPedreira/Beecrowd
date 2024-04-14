#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
#define MOD 1000000007

int avenue[MAX] = {1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c;
  cin >> c;
  while (c--) {
    int n, m;
    cin >> n >> m;
    vector<int> radars(m);
    for (int i = 0; i < m; i++)
      cin >> radars[i];

    if (m == 1)
      cout << 1 << endl;
    else {
      for (int i = 1; i <= n; i++)
        avenue[i] = 0;

      for (int i = 0; i < n; i++) {
        if (avenue[i] || i == 0) {
          for (int j = 0; j < m; j++) {
            if (i + radars[j] < n)
              avenue[i + radars[j]] =
                  ((avenue[i + radars[j]] % MOD) + (avenue[i] % MOD)) % MOD;
            else {
              avenue[n] = ((avenue[n] % MOD) + (avenue[i] % MOD)) % MOD;
            }
          }
        }
      }

      cout << avenue[n] << endl;
    }
  }
}