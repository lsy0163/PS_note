#include <bits/stdc++.h>
using namespace std;
int n;
bool flag;
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int m, temp;
  for(int i=1; i<=n; i++){
    temp = i;
    m = i;
    while(temp != 0){
      m += (temp % 10);
      temp /= 10;
    }
    if(m == n){
      flag = true;
      cout << i << "\n";
      break;
    }
  }
  if(!flag){ cout << 0 << "\n"; }
  return 0;
}