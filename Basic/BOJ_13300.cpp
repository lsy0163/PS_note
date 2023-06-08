#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 0;
int a[2][7] = {};

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int s, y;  // 성별, 학년
    cin >> s >> y;
    a[s][y]++;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < 7; j++) {
      ans += a[i][j] / K;
      if (a[i][j] % K != 0) ans++;
    }
  }
  cout << ans << "\n";
}