#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int cash[100];
int cache[10001];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> cash[i];
  }

  sort(cash, cash + n);

  for (int i = 0; i <= m; i++) {
    cache[i] = 10001;
  }

  cache[0] = 0;
  for (int i = cash[0]; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if (i - cash[j] < 0) break;
      if (cache[i - cash[j]] == 10001) continue;

      cache[i] = min(cache[i], cache[i - cash[j]] + 1);
    }
  }

  if (cache[m] == 10001) {
    cout << -1 << "\n";
  } else {
    cout << cache[m] << "\n";
  }

  return 0;
}