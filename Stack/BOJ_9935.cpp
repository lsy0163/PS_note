#include <bits/stdc++.h>
using namespace std;

string str, bomb;
string ans = "";

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> str >> bomb;

  int bombIdx = bomb.length() - 1;
  for (int i = 0; i < str.length(); i++) {
    ans += str[i];
    if (ans[ans.length() - 1] == bomb[bombIdx]) {
      if (ans.length() >= bomb.length()) {
        int cnt = 1;
        for (int j = bombIdx - 1; j >= 0; j--) {
          if (ans[ans.length() - 1 - (bombIdx - j)] == bomb[j]) cnt++;
        }
        if (bomb.length() == cnt) {
          for (int j = 0; j < bomb.length(); j++) {
            ans.pop_back();
          }
        }
      }
    }
  }
  if (!ans.empty()) {
    cout << ans << "\n";
  } else
    cout << "FRULA\n";
}