#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> gaps;
  int gap_sum = 0;

  int before, now;
  cin >> before;

  for (int i = 2; i <= N; i++) {
    cin >> now;

    int gap = now - before;
    gaps.push_back(gap);
    gap_sum += gap;

    before = now;
  }

  sort(gaps.begin(), gaps.end());

  for (int i = 1; i < K; i++) {
    gap_sum -= gaps[N - i];
  }

  cout << gap_sum << endl;

  return 0;
}