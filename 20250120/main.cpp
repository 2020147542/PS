#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define INF 100000

using namespace std;

int N, M, s_city, e_city;
vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> cities;  // {최소 비용, 직전 노드}
vector<bool> visited;

void find_cost(int current_node, int current_cost) {
  visited[current_node] = true;

  for (auto node : graph[current_node]) {
    int next_node = node.first;
    int next_cost = current_cost + node.second;

    // 최소 비용 갱신
    if (cities[next_node].first > next_cost) {
      cities[next_node].first = next_cost;
      cities[next_node].second = current_node;
    }
  }

  // 다음 방문할 노드 선택
  sort(cities.begin(), cities.end(), [&](pair<int, int> a, pair<int, int> b) {
    return (!visited[a.second] && a.first < b.first);
  });

  
    if (!visited[1] && cities[1].first < INF) {
      find_cost(, cities[1].first);
      return;
    }

}

int main() {
  cin >> N >> M;

  graph.resize(N + 1);
  cities.resize(N + 1, {INF, INF});
  visited.resize(N + 1, false);

  int a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }

  cin >> s_city >> e_city;

  cities[s_city].first = 0;        // 시작 노드의 최소 비용 초기화
  cities[s_city].second = s_city;  // 시작 노드의 직전 노드는 자기 자신

  find_cost(s_city, 0);

  // 도착 노드의 최소 비용 출력
  cout << cities[e_city].first << endl;

  return 0;
}
