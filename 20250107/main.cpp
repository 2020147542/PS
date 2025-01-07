#include <iostream>
#include <vector>

using namespace std;

int N, S, total;
vector<int> arr;

int solution(int s_idx) {
  int sum = 0;

  for (int i = s_idx; i < N; i++) {
    sum += arr[i];

    if (sum == S) {
      total++;
      return i;
    }
  }

  return -1;
}

int main() {
  cin >> N >> S;

  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    int newBegin = solution(i);
    if (newBegin >= 0) {
      i = newBegin;
    }
  }

  cout << total << endl;

  return 0;
}