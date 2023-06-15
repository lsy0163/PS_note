#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;        // 페이지 수
ll cnt[10];  // 각 숫자가 몇 번 나왔는지 count하는 배열

void calc(ll n, ll ten) {  // ten은 자리수
  while (n > 0) {
    cnt[n % 10] += ten;
    n /= 10;
  }
}

void solve(ll A, ll B, ll ten) {
  // A를 ++해서 1의 자리수를 0으로 만들기
  while (A % 10 != 0 && A <= B) {
    // ++할 때 나오는 각 숫자들을 count
    calc(A, ten);
    A++;
  }
  if (A > B) return;

  while (B % 10 != 9 && B >= A) {
    calc(B, ten);
    B--;
  }

  int x = (B / 10 - A / 10 + 1);
  for (int i = 0; i < 10; i++) {
    cnt[i] += x * ten;
  }

  solve(A / 10, B / 10, ten * 10);
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  solve(1, N, 1);
  for (int i = 0; i < 10; i++) {
    cout << cnt[i] << " ";
  }
  cout << "\n";
}