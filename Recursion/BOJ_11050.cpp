#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
  if (k == 0) return 1;
  if (k == n) return 1;
  return solve(n - 1, k - 1) + solve(n - 1, k);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << "\n";
}