#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int matches, balance;
  while (cin >> matches >> balance) {
    int ans = 0;
    bool flag = true;
    vector<int> diff;
    for (int i = 0; i < matches; i++) {
      int a, b;
      cin >> a >> b;
      if (b < a) {
        ans += 3;
      } else {
        diff.push_back(b - a);
      }
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < diff.size() && flag; i++) {
      if (diff[i] < balance) {
        ans += 3;
        balance -= (diff[i] + 1);
      } else if (diff[i] == balance) {
        ans++;
        balance -= (diff[i] + 1);
      } else if (diff[i] > balance && diff[i] == 0) {
        ans++;
      } else
        flag = false;
    }
    cout << ans << endl;
  }
}