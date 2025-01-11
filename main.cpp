#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}

int main() {
  int N;
  vector<pair<int, int>> tree;

  cin >> N;
  tree.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> tree[i].first;
  }

  for (int i = 0; i < N; i++) {
    cin >> tree[i].second;
  }

  sort(tree.begin(), tree.end(), compare);

  long totalTreeLength = 0;
  for (int day = 0; day < N; day++) {
    totalTreeLength += tree[day].first + (tree[day].second * day);
  }

  cout << totalTreeLength << endl;
  return 0;
}