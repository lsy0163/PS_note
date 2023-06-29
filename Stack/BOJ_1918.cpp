// 중위 표기식 후위 표기식으로 변환하기
#include <bits/stdc++.h>
using namespace std;

stack<char> s;

// 연산자 우선순위 반환
int prec(char op) {
  switch (op) {
    case '(':
    case ')':
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
  }
  return -1;  // 지정되지 않은 연산자
}

void infix_to_postfix(const string& exp) {
  for (auto& e : exp) {
    switch (e) {
      case '+':
      case '-':
      case '*':
      case '/':  // 연산자인 경우{
        while (!s.empty() && prec(e) <= prec(s.top())) {
          cout << s.top();
          s.pop();
        }
        s.push(e);
        break;

      case '(': {
        s.push('(');
        break;
      }

      case ')': {
        char top_op = s.top();
        s.pop();
        while (top_op != '(') {
          cout << top_op;
          top_op = s.top();
          s.pop();
        }
        break;
      }
      default: {
        cout << e;
      }
    }
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << "\n";
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string exp;
  cin >> exp;
  infix_to_postfix(exp);
}