#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 99999999

vector<int> dijkstra(int start, int V, vector<pair<int, int> > adj[]) {
  vector<int> dist(V, INF);  // 초기에 모두 INF로 초기화
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  dist[start] = 0;      // 시작하는 지점의 dist 0으로 설정
  pq.push({0, start});  // 시작 정점 방문

  while (!pq.empty()) {
    int cost = pq.top().first;  // 방문 정점의 dist 값
    int cur = pq.top().second;  // 방문 정점
    pq.pop();

    for (int i = 0; i < adj[cur].size(); i++) {
      int next = adj[cur][i].first;           // 조사할 다음 정점
      int ncost = cost + adj[cur][i].second;  // 조사할 정점의 cost
      if (ncost < dist[next]) {
        dist[next] = ncost;  // dist보다 cost가 더 작으면 갱신
        pq.push({ncost, next});
      }
    }
  }
  return dist;
}

int main(void) {
  int V, E;
  vector<pair<int, int> > adj[MAX];

  cout << "정점 개수 입력 : ";
  cin >> V;
  cout << "간선 개수 입력 : ";
  cin >> E;

  for (int i = 0; i < E; i++) {
    int from, to, cost;
    cout << "그래프 입력 [정점 정점 가중치] : ";
    cin >> from >> to >> cost;
    adj[from].push_back({to, cost});
    adj[to].push_back({from, cost});
  }

  vector<int> dist = dijkstra(0, V, adj);
  for (int i = 0; i < V; i++) {
    cout << "0번 정점에서 " << i << "번 정점까지 최단거리 : " << dist[i] << "\n";
  }
}