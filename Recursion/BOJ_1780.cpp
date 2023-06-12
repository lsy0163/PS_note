#include <bits/stdc++.h>
using namespace std;
int n;
int paper[2200][2200];  // 종이 입력 2차원 배열
int cnt[3];             // -1, 0, 1 종이 개수 count cnt[0] -> -1 종이 개수

bool check(int x, int y, int z) {
  for (int i = x; i < x + z; i++) {
    for (int j = y; j < y + z; j++) {
      if (paper[x][y] != paper[i][j]) return false;
    }
  }
  return true;
}

void solve(int x, int y, int z) {  // x, y 부터 z*z 배열
  if (check(x, y, z)) {
    cnt[paper[x][y] + 1] += 1;
    return;
  }
  int n = z / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      solve(x + i * n, y + j * n, n);
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> paper[i][j];
    }
  }
  solve(0, 0, n);
  for (auto& e : cnt) {
    cout << e << "\n";
  }
}