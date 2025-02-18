#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pir;

int n, ans;
int cache[100];
pir lines[100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의
  // 최소 개수
  // 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> lines[i].first >> lines[i].second;
    cache[i] = 1;  // 자기 자신 포함
  }

  sort(lines, lines + n);

  ans = cache[0];
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (lines[j].second < lines[i].second) {
        cache[i] = max(cache[i], cache[j] + 1);  // 이전 최대 수 + 1
      }
    }

    ans = max(ans, cache[i]);
  }

  cout << n - ans << "\n";

  return 0;
}