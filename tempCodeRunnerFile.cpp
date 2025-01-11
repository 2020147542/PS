#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> tree;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}

int main() {
  cin >> N;

  tree.resize(N);

  int h, a;
  for (int i = 0; i < N; i++) {
    cin >> h >> a;
    tree[N] = {h, a};
  }

  for (auto a : tree) {
    cout << a.first << ", " << a.second << endl;
  }
  cout << endl;

  sort(tree.begin(), tree.end(), compare);

  for (auto a : tree) {
    cout << a.first << ", " << a.second << endl;
  }

  return 0;
}