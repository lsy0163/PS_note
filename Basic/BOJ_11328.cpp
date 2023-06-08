#include <bits/stdc++.h>
using namespace std;
int N;  // testcase

string s1, s2;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    int cnt1[26] = {};  // 0~25는 a~z 각 알파벳이 몇 번 나왔는지를 저장함
    int cnt2[26] = {};
    int flag = 1;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
      cnt1[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++) {
      cnt2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt1[i] != cnt2[i]) {
        flag = 0;
        break;
      }
    }
    if (flag)
      cout << "Possible"
           << "\n";
    else
      cout << "Impossible"
           << "\n";
  }
}

/*
strfry -> 문자열 무작위 재배열
알파벳 배열 선언 2개 -> 0으로 초기화
원래 문자열을 탐색해서 알파벳 배열 각 원소 값 갱신
뒤의 문자열을 탐색해서 알파벳 배열 하나 더 만듬
이 두 개 비교해서 모든 원소의 값이 같으면  Possible, 하나라도 다른 거 있으면 Impossible
*/