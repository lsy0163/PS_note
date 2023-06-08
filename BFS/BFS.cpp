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
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int, int> > Q;
  vis[0][0] = 1;  // (0, 0) 시작점부터 방문 시작
  Q.push({0, 0});
  while (!Q.empty()) {  // Q가 비어있으면 더 이상 탐색 못함
    pair<int, int> cur = Q.front();
    Q.pop();
    cout << "(" << cur.X << ", " << cur.Y << ") -> ";
    for (int dir = 0; dir < 4; dir++) {  // 상하좌우 칸 탐색
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];                              // nx, ny에 다음 탐색할 좌표 넣어줌
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  // board의 범위를 벗어나는 경우엔 넘어감
      if (vis[nx][ny] || board[nx][ny] != 1) continue;       // 이미 방문했던 칸이거나, 빨강 칸이면(갈 수 없는 칸이면) 넘어감
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}