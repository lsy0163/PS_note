#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] =
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};  // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502];                    // 해당 칸의 방문 여부 저장 처음에는 전부 0
int n = 7, m = 10;                     // board의 행과 열의 크기
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};  // 상하좌우 네 방향을 나타네는 방향벡터(x가 행, y가 열을 나타냄)

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  stack<pair<int, int> > S;
  vis[0][0] = 1;
  S.push({0, 0});
  while (!S.empty()) {
    pair<int, int> cur = S.top();
    S.pop();
    cout << "(" << cur.X << ", " << cur.Y << ") -> ";
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = 1;
      S.push({nx, ny});
    }
  }
}
