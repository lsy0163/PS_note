#include <bits/stdc++.h>
// 양수인 부분 수열 모두 탐색 -> 최대 : 2^20
using namespace std;
int a[21];
int n, s, cnt=0;

void go(int cur, int total){
  if(cur == n){
    if(total == s) cnt++;
    return;
  }
  go(cur+1, total); //cur 포함 x
  go(cur+1, total+a[cur]); // cur 포함한 경우
}

int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  go(0, 0);
  if(s==0) cnt--; // s가 0일 땐 1번더 더해주기 때문에 빼줘야 됨
  cout << cnt << "\n";
}