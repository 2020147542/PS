#include <algorithm>
#include <iostream>
using namespace std;

int n, ans = 1;
int arr[1001];
int cache[1001];  // i번째를 반드시 포함할 때 가장 긴 증가 부분 수열의 수

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cache[i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (arr[i] > arr[j]) {
        cache[i] = max(cache[i], cache[j] + 1);
      }
    }

    ans = max(ans, cache[i]);
  }

  cout << ans << "\n";

  return 0;
}