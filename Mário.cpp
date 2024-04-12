#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int values[MAX] = {0}, sumPrefix[MAX] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l;
  while (cin >> n >> l && n && l) {
    for (int i = 1; i <= l; i++) {
      cin >> values[i];
      sumPrefix[i] = sumPrefix[i - 1] + (values[i] - values[i - 1] - 1);
    }

    if (n == 1) {
      cout << 0 << endl;
    } else {
      int ans = INT_MAX;

      for (int i = 1, j = 1; j <= l && i + n - 1 <= values[l]; i++) {
        while (values[j] - values[i] + 1 < n && j <= l) {
          j++;
        }
        if (values[j] - values[i] + 1 == n) {
          ans = min(ans, sumPrefix[j] - sumPrefix[i]);
          j++;
        } else if (values[j] - values[i] + 1 > n) {
          ans = min(ans, sumPrefix[j - 1] - sumPrefix[i] +
                             (values[i] + n - values[j - 1] - 1));
        }
      }

      cout << ans << endl;
    }
  }
}