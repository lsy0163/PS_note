#include <bits/stdc++.h>
using namespace std;

int num_set[1000002];

int getParent(int parent[], int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent, parent[x]);
}

// 각 부모 노드 합치는 함수
void unionParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  if (a < b)  // 최상단 루트 노드를 더 작은 값으로 유지함.
    parent[b] = a;
  else
    parent[a] = b;
}

// 같은 부모 노드를 갖는지 확인(같은 집합에 속하는지)
int findParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  if (a == b)
    return 1;
  else
    return 0;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int x, a, b;

  for (int i = 0; i <= n; i++) {  // 초기에 모든 배열 다른 집합에 속하도록 초기화
    num_set[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> x >> a >> b;
    if (x == 0) {
      unionParent(num_set, a, b);
    }
    if (x == 1) {
      if (findParent(num_set, a, b)) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    }
  }
}