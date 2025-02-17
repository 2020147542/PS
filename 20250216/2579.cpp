#include <algorithm>
#include <iostream>
using namespace std;

int n;
int stair[301];
int cache[301];

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 한번에 한 칸 또는 두칸식 오름
  // 연속된 세 계단을 밟아서는 안됨
  // 마지막 도착 계단은 반드시 밟아야 함.
  // dp 정의: 현재 계단을 밟았을 떄, 최고점
  // 직전에 계단을 올랐는가 아닌가에 영향을 받음
  // 직전에 밟은 경우 -> 3칸 전에 밟고 + 직전 밟고 + 지금 밟고
  // 직전에 안밟은 경우 -> 2칸 전에 밟고 + 지금 밟고
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> stair[i];
  }

  cache[1] = stair[1];
  cache[2] = stair[1] + stair[2];
  for (int i = 3; i <= n; i++) {
    cache[i] = max(cache[i - 3] + stair[i - 1], cache[i - 2]) + stair[i];
  }

  cout << cache[n] << "\n";

  return 0;
}