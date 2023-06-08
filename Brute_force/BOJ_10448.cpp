#include <bits/stdc++.h>
using namespace std;
int t, T[51], n;
int N = 51;
bool go(int sum){
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        for(int k=1; k<=N; k++){
          if(T[i] + T[j] + T[k] == n) return true;
        }
      }
    }
    return false;
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  T[1] = 1;
  for(int i=2; i<=50; i++){
    T[i] = T[i-1] + i;
  }
  while(t--){
    cin >> n;
    cout << go(n) << "\n";
  }
}