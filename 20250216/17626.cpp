// #include <cstdio>
#include <iostream>
using namespace std;

int n;
int cache[50001];

// 0.5초 = 5 * 10e7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  cin >> n;

  cache[0] = 0;

  for (int i = 1; i <= n; i++) {
    cache[i] = 500001;

    for (int j = 1; j * j <= i; j++) {
      cache[i] = min(cache[i], cache[i - j * j] + 1);
    }
  }

  cout << cache[n] << "\n";
  return 0;
}