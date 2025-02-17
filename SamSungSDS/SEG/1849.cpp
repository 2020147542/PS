#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, H, half_size, tree_size;
vector<int> A;
vector<int> SEG;
vector<int> ans;

// k번째 빈자리 index return
int query(int k, int cur_idx) {
  if (SEG[cur_idx] == 0) return 0;
  if (cur_idx >= half_size) return cur_idx;

  int l = 0, r = 0;
  if (SEG[cur_idx * 2] >= k) {
    l = query(k, cur_idx * 2);
  } else {
    r = query(k - SEG[cur_idx * 2], cur_idx * 2 + 1);
  }

  return l + r;
}

void update(int idx, int value) {
  SEG[idx] = value;
  while (idx) {
    idx /= 2;
    SEG[idx] = SEG[idx * 2] + SEG[idx * 2 + 1];
  }
}

void init() {
  for (int i = half_size - 1; i >= 1; i--) {
    SEG[i] = SEG[i * 2] + SEG[i * 2 + 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  cin >> N;
  A.resize(N);  // 0부터 시작
  ans.resize(N);

  H = (int)ceil(log2(N));
  half_size = 1 << H;
  tree_size = 2 * half_size;
  SEG.resize(tree_size + 1, 0);  // 1부터 시작

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    SEG[half_size + i] = 1;  // 빈자리 개수 표시
  }

  init();

  // 작은 숫자부터 차례대로 빈칸 채우기
  for (int i = 0; i < N; i++) {
    int pos = query(A[i] + 1, 1);
    update(pos, 0);
    ans[pos - half_size] = i + 1;
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}