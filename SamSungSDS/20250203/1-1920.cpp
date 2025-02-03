#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;

bool bin_search(int a) {
  int s = 0;
  int e = N - 1;

  while (s <= e) {
    int mid = (s + e) / 2;

    if (A[mid] == a)
      return true;
    else if (A[mid] < a) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;
  A.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  cin >> M;
  int a;
  for (int i = 0; i < M; i++) {
    cin >> a;
    cout << binary_search(A.begin(), A.end(), a) << '\n';
  }

  return 0;
}