#include <iostream>
#include <vector>

using namespace std;

int N, S, total;
vector<int> arr;

void solution(int s_idx, int sum) {
  if (s_idx == N) {
    if (sum == S) total++;

    return;
  }

  solution(s_idx + 1, sum + arr[s_idx]);
  solution(s_idx + 1, sum);
}

int main() {
  cin >> N >> S;

  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  solution(0, 0);

  if (S == 0) {
    total -= 1;  // 아무것도 선택하지 않을 확률 하나 제거
  }

  cout << total << endl;

  return 0;
}