#include <algorithm>
#include <iostream>
using namespace std;

int N;
const int MAX = 10e6;
int cache[MAX];  // i가 1이 될 떄의 최소 연산 횟수

// int dp(int x) {
//   if (x <= 1) return 0;
//   if (cache[x]) return cache[x];

//   cache[x] = MAX;
//   if (x % 3 == 0) {
//     cache[x] = min(cache[x], dp(x / 3) + 1);
//   }

//   if (x % 2 == 0) {
//     cache[x] = min(cache[x], dp(x / 2) + 1);
//   }

//   return cache[x] = min(cache[x], dp(x - 1) + 1);
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  cache[0] = MAX;
  cache[2] = 1;
  cache[3] = 1;

  for (int i = 4; i <= N; i++) {
    int a = i % 3 == 0 ? i / 3 : 0;
    int b = i % 2 == 0 ? i / 2 : 0;
    int c = i - 1;

    cache[i] = min({cache[a], cache[b], cache[c]}) + 1;
  }

  cout << cache[N] << "\n";
  // cout << dp(N) << "\n";

  return 0;
}