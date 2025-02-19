#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[100];
const int MAX_VALUE = 100001;
vector<int> cache(10001, MAX_VALUE);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cache[0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i < arr[j]) continue;
      cache[i] = min(cache[i - arr[j]] + 1, cache[i]);
    }
  }

  if (cache[k] == MAX_VALUE) {
    cout << -1 << "\n";
  } else {
    cout << cache[k] << "\n";
  }

  return 0;
}