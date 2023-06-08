#include <bits/stdc++.h>
using namespace std;

using ll = long long;  // long long type을 ll로 씀

ll pow(ll a, ll b, ll c) {  // 정답을 계산해서 리턴하는 함수
  if (b == 1) return a % c;
  ll val = pow(a, b / 2, c);
  val = val * val % c;
  if (b % 2 == 0) return val;
  return val * a % c;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << pow(a, b, c) << "\n";
}