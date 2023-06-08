#include <bits/stdc++.h>
using namespace std;
string board[51];
int n, m, ans=64, temp;
string white[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
};

string black[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
};

int white_board(int x, int y){
  int cnt = 0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(white[i][j] != board[x+i][y+j]) cnt++;
    }
  }
  return cnt;
}

int black_board(int x, int y){
  int cnt = 0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(black[i][j] != board[x+i][y+j]) cnt++;
    }
  }
  return cnt;
}

int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> board[i];
  }
  for(int i=0; i<=n-8; i++){
    for(int j=0; j<=m-8; j++){
      temp = min(white_board(i, j), black_board(i, j));
      ans = min(ans, temp);
    }
  }
  cout << ans << "\n";
}