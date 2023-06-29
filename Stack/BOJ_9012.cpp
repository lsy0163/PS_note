// 괄호 검사 문제
#include <bits/stdc++.h>
using namespace std;
int t;

int solve(const string& str) {
  stack<char> s;
  char ch, open_ch;
  for (auto e : str) {
    switch (e) {
      case '(':
        s.push(e);
        break;
      case ')':
        if (s.empty())
          return 0;
        else
          s.pop();
    }
  }
  if (!s.empty()) return 0;
  return 1;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> t;
  while (t--) {
    cin >> str;
    if (solve(str))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}