#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
long M;
vector<int> trees;

int binary_cut() {
  int start = 0;
  int end = trees[0];

  while (start <= end) {
    int h = (start + end) / 2;
    long sum = 0;

    for (int i = 0; i < N; i++) {
      if (trees[i] > h) {
        sum += trees[i] - h;
      } else {
        break;
      }
    }

    if (sum >= M) {
      if (h + 1 >= trees[0]) {
        return h;
      }

      start = h + 1;
    } else {
      if (h - 1 <= 0) {
        return h;
      }

      end = h - 1;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  trees.resize(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> trees[i];
  }

  sort(trees.rbegin(), trees.rend());

  cout << binary_cut() << '\n';

  return 0;
}