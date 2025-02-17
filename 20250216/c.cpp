#include <iostream>
using namespace std;

int n;
const int MOD = 796796;
int cache[1001];

int main() {
  cin >> n;

  cache[1] = 1;
  cache[2] = cache[1] + 2;

  for (int i = 3; i <= n; i++) {
    cache[i] = cache[i - 2] * 2 + cache[i - 1];
  }

  cout << cache[n] << "\n";

  return 0;
}