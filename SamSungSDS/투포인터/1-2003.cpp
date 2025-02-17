#include <iostream>
using namespace std;

int N, M, ll, rr, cnt;
int A[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  while (ll <= rr && rr < N) {
    int sum = 0;

    for (int i = ll; i <= rr; i++) {
      sum += A[i];
    }

    if (sum >= M) {
      if (sum == M) cnt++;
      ll++;
    } else {
      rr++;
    }
  }

  cout << cnt << '\n';

  return 0;
}