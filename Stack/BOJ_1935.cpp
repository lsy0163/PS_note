// 후위 표기식 계산(스택)
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;       // 피연산자의 개수
  string exp;  // 후위 표기식
  cin >> n >> exp;

  vector<int> v(n);
  stack<double> s;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (auto& e : exp) {
    if (e != '+' && e != '-' && e != '/' && e != '*') {  // 피연산자인 경우 스택에 push
      s.push(v[e - 'A']);
    } else {  // 연산자인 경우 피연산자를 스택에서 꺼내서 계산 후 다시 저장
      double op2 = s.top();
      s.pop();
      double op1 = s.top();
      s.pop();
      switch (e) {
        case '+':
          s.push(op1 + op2);
          break;
        case '-':
          s.push(op1 - op2);
          break;
        case '/':
          s.push(op1 / op2);
          break;
        case '*':
          s.push(op1 * op2);
          break;
      }
    }
  }
  cout << fixed;
  cout.precision(2);
  cout << s.top() << "\n";
}