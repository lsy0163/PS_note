#include <bits/stdc++.h>
using namespace std;
int n;
int main(void) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= i; j--) {
      cout << " ";
    }
    for (int k = 1; k <= 2 * i - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = n - 1; j >= i; j--) {
      cout << " ";
    }
    for (int k = 1; k <= 2 * i - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
}