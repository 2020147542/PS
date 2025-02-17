#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, M, K;
int a, b;
ll c;
vector<ll> arr;
vector<ll> SEG;

ll init(int left, int right, int cur) {
  if (left == right) return SEG[cur] = arr[left];

  int mid = (left + right) / 2;
  return SEG[cur] =
             init(left, mid, cur * 2) + init(mid + 1, right, cur * 2 + 1);
}

ll query(int i, int j, int left, int right, int cur) {
  if (j < left || right < i) return 0ll;
  if (i <= left && right <= j) return SEG[cur];

  int mid = (left + right) / 2;
  return query(i, j, left, mid, cur * 2) +
         query(i, j, mid + 1, right, cur * 2 + 1);
}

ll update(int idx, ll value, int left, int right, int cur) {
  if (idx < left || idx > right) return SEG[cur];
  if (left == right) return SEG[cur] = value;

  int mid = (left + right) / 2;
  return SEG[cur] = update(idx, value, left, mid, cur * 2) +
                    update(idx, value, mid + 1, right, cur * 2 + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  cin >> N >> M >> K;
  int h = (int)ceil(log2(N));
  int tree_size = (1 << (h + 1));  // 2^(H+1)

  arr.resize(N);
  SEG.resize(tree_size);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  init(0, N - 1, 1);

  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;

    if (a == 1) {
      // 수 변경
      update(b - 1, c, 0, N - 1, 1);
    } else {
      // 구간 합 출력
      cout << query(b - 1, c - 1, 0, N - 1, 1) << "\n";
    }
  }

  return 0;
}