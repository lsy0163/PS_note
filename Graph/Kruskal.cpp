#include <bits/stdc++.h>

using namespace std;

int num_set[1002];

// 부모 노드 가져오기
int getParent(int set[], int x) {
  if (set[x] == x) return x;
  return set[x] = getParent(set, set[x]);
}

// 부모 노드 병합
void unionParent(int set[], int a, int b) {
  a = getParent(set, a);
  b = getParent(set, b);
  if (a < b)
    set[b] = a;
  else
    set[a] = b;
}

int find(int set[], int a, int b) {
  a = getParent(set, a);
  b = getParent(set, b);

  if (a == b)
    return 1;
  else
    return 0;
}

class Edge {
 public:
  int node[2];
  int distance;
  Edge(int a, int b, int distance) {
    this->node[0] = a;
    this->node[1] = b;
    this->distance = distance;
  }

  bool operator<(const Edge& edge) const {
    return this->distance < edge.distance;
  }
};

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  vector<Edge> v;
  cin >> n;
  cin >> m;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    v.push_back(Edge(a, b, c));
  }

  // 간선 비용 기준 오름차순 정렬
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    num_set[i] = i;
  }
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    // 사이클이 생기지 않는 경우에만 선택
    if (!find(num_set, v[i].node[0] - 1, v[i].node[1] - 1)) {
      sum += v[i].distance;
      unionParent(num_set, v[i].node[0] - 1, v[i].node[1] - 1);
    }
  }

  cout << sum << "\n";
}