#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int INF = 999999999;
vector<int> arr;
vector<int> sum;
vector<vector<int>> cache;

int f(int k, int cur) {
  if (k == 0) return 0;
  if (cur <= 0) return -INF;
  if (cache[k][cur] != -1) return cache[k][cur];

  int sum = 0;
  for (int i = cur; i > 0; i--) {
    sum += arr[i];
    cache[k][cur] = max(f(k, cur - 1), f(k - 1, cur - 2) + arr[i]);
  }
  return cache[k][cur];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  arr.resize(n + 1);
  cache.resize(n / 2 + 1, vector<int>(n + 1, -1));

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  return 0;
}