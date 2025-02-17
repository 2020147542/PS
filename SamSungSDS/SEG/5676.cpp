#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 10e5;
int N, K, a, b;
short arr[MAX];
short SEG[4 * MAX];

short init(int cur, int left, int right) {
  if (left == right) {
    return SEG[cur] = arr[left];
  }

  int mid = (left + right) / 2;
  return SEG[cur] =
             init(cur * 2, left, mid) * init(cur * 2 + 1, mid + 1, right);
}

short query(int i, int j, int cur, int left, int right) {
  if (j < left || right < i) return 1;
  if (i <= left && right <= j) return SEG[cur];

  int mid = (left + right) / 2;
  return query(i, j, cur * 2, left, mid) *
         query(i, j, cur * 2 + 1, mid + 1, right);
}

short update(int idx, int value, int cur, int left, int right) {
  if (idx < left || idx > right) return SEG[cur];
  if (left == right) return SEG[cur] = value;

  int mid = (left + right) / 2;
  return SEG[cur] = update(idx, value, cur * 2, left, mid) *
                    update(idx, value, cur * 2 + 1, mid + 1, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> N >> K) {
    memset(arr, 0, sizeof(arr));
    memset(SEG, 0, sizeof(SEG));

    for (int i = 0; i < N; i++) {
      short num;
      cin >> num;
      arr[i] = num ? num > 0 ? 1 : -1 : 0;
    }

    init(1, 0, N - 1);

    char command;
    for (int i = 0; i < K; i++) {
      cin >> command >> a >> b;

      if (command == 'C') {
        b = b ? b > 0 ? 1 : -1 : 0;
        update(a - 1, b, 1, 0, N - 1);

      } else {
        short res = query(a - 1, b - 1, 1, 0, N - 1);
        cout << (res ? res > 0 ? '+' : '-' : '0');
      }
    }

    cout << "\n";
  }

  return 0;
}