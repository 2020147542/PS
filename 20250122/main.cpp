#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> expected(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    cin >> expected[i];
  }

  sort(expected.begin(), expected.end());

  long gap_score = 0;

  for (int i = 1; i <= N; i++) {
    gap_score += abs(i - expected[i]);
  }

  cout << gap_score << endl;
  return 0;
}