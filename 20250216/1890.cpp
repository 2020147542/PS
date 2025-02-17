#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

int n;
int arr[100][100];
ll cache[100][100];

ll dp(int r, int c) {
  if (r >= n || c >= n) return 0ll;
  if (r == n - 1 && c == n - 1) return 1ll;
  if (arr[r][c] == 0) return 0ll;  // 0보다 크거나 같고, 9보다 작거나 같은 정수
  if (cache[r][c] != -1) return cache[r][c];

  return cache[r][c] = dp(r + arr[r][c], c) + dp(r, c + arr[r][c]);
}

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것
  // 각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리
  // 오른쪽이나 아래쪽으로만 이동해야 한다
  // 0은 더 이상 진행을 막는 종착점
  // 한 번 점프를 할 때, 방향을 바꾸면 안 된다.
  // 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는
  // 경로의 개수
  freopen("input.txt", "r", stdin);

  cin >> n;
  memset(cache, -1ll, sizeof(cache));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  cout << dp(0, 0) << "\n";
  return 0;
}