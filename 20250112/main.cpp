#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  vector<int> A_arr(A, 0);
  vector<int> B_arr(B, 0);

  for (int i = 0; i < A; i++) {
    cin >> A_arr[i];
  }

  for (int i = 0; i < B; i++) {
    cin >> B_arr[i];
  }

  // 정렬
  sort(A_arr.begin(), A_arr.end());
  sort(B_arr.begin(), B_arr.end());

  // count
  long total = 0;
  if (N % 2 == 1) {
    total += A_arr[A - 1];
    A_arr.pop_back();
  }

  for (int i = 0; i < N / 2; i++) {
    int a_length = A_arr.size();
    int b_length = B_arr.size();

    int a_value = a_length >= 2 ? A_arr[a_length - 1] + A_arr[a_length - 2] : 0;
    int b_value = b_length >= 1 ? B_arr[b_length - 1] : 0;

    if (a_value > b_value) {
      total += a_value;
      A_arr.pop_back();
      A_arr.pop_back();

    } else {
      total += b_value;
      B_arr.pop_back();
    }
  }

  cout << total << endl;

  return 0;
}