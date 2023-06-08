#include <bits/stdc++.h>
using namespace std;

string s1, s2;  // 입력으로 받는 문자열을 저장할 변수 선언
int cnt1[26];
int cnt2[26];
int ans = 0;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2;
  for (auto e : s1) {
    cnt1[e - 'a']++;
  }
  for (auto e : s2) {
    cnt2[e - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt1[i] < cnt2[i])
      ans += cnt2[i] - cnt1[i];
    else if (cnt1[i] > cnt2[i])
      ans += cnt1[i] - cnt2[i];
  }
  cout << ans << "\n";
}

/*
애너그램 만들기
str1, str2 가 서로 없는 문자열 개수를 모두 count
*/