#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M, max_h;
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

    if (sum == M) {
      return h;
    } else if (sum > M) {
      // 무조건 sum과 M이 같을 거라는 보장 없음
      // start가 end를 넘어가면 아무값도 return 하지 않음
      // 항상 가질 수 있는 현재의 최대 height를 저장해 두어야 함
      if (max_h < h) max_h = h;
      start = h + 1;
    } else {
      end = h - 1;
    }
  }

  return max_h;
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