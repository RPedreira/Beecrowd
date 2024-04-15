#include <bits/stdc++.h>
using namespace std;

int gifts[10001];

bool solve(int last, int index, int sideA, int sideB, bool ans) {
  if (index == last) {
    if (abs((sideA + gifts[index]) - sideB) <= 5 ||
        abs((sideB + gifts[index]) - sideA) <= 5)
      return true;
    else
      return false;
  }
  if (abs((sideA + gifts[index]) - sideB) <= 5)
    ans |= solve(last, index + 1, sideA + gifts[index], sideB, ans);
  if (abs((sideB + gifts[index]) - sideA) <= 5 && !ans)
    ans |= solve(last, index + 1, sideA, sideB + gifts[index], ans);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    bool ans;
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> gifts[i];

    ans = solve(n, 1, 0, 0, false);
    if (ans)
      cout << "Feliz Natal!" << endl;
    else
      cout << "Ho Ho Ho!" << endl;
  }
}