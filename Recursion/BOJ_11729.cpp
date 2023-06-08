#include <bits/stdc++.h>
using namespace std;

void go(int a, int b, int n) {
  if (n == 1) {
    cout << a << " " << b << "\n";
    return;
  }
  go(a, 6 - b - a, n - 1);
  cout << a << " " << b << "\n";
  go(6 - b - a, b, n - 1);
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (1 << n) - 1 << "\n";
  go(1, 3, n);
}
