#include <bits/stdc++.h>
using namespace std;
int n, st, ba;
string N;
bool fail[1000]; // true인 index는 정답이 될 수 없음

void check(string str, int st, int ba){
  int a, b;
  for(int i=123; i<988; i++){
    if(fail[i]) continue;
    a = 0, b = 0;
    string tmp = to_string(i);
    for(int j=0; j<3; j++){
      for(int k=0; k<3; k++){
        if(str[j] == tmp[k]){
          if(j == k) a++;
          else b++;
        }
      }
    }
    if(a != st || b != ba) fail[i] = true;
  }
}

int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // a 배열 false로 초기화
  memset(fail, false, 1000*sizeof(bool));
  cin >> n;
  while(n--){
    cin >> N >> st >> ba;
    check(N, st, ba);
  }
  int ans = 0;
  int num = 0;
  for(int i=1; i<10; i++){
    for(int j=1; j<10; j++){
      if(i==j) continue;
      for(int k=1; k<10; k++){
        if(k==i || k==j) continue;
        num = i*100 + j*10 + k;
        if(!fail[num]) ans++;
      }
    }
  }
  cout << ans << "\n";
}