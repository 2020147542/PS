#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
const int MAX = 100;
vector<int> recomd(MAX + 1, 0);  // 추천 횟수
vector<int> when(MAX + 1, 0);    // 추천 받은 순서

void solution(int idx, int student) {
  // 이미 추천 받은 경우
  if (recomd[student] > 0) {
    recomd[student]++;
  } else {
    // 빈 액자가 남아 있는 경우
    if (cnt < N) {
      recomd[student] = 1;
      when[student] = idx;
      cnt++;
    } else {
      // 액자를 뺏어야 하는 경우
      // 추천 받은 횟수가 동일할 때 가장 오래된 사진 삭제
      int ready_to_change;
      int least_recomd = 1111;
      for (int i = 1; i <= MAX; i++) {
        if (recomd[i] > 0) {
          if (recomd[i] < least_recomd) {
            least_recomd = recomd[i];
            ready_to_change = i;
          } else if (recomd[i] == least_recomd) {
            if (when[i] < when[ready_to_change]) {
              ready_to_change = i;
            }
          }
        }
      }

      recomd[ready_to_change] = 0;
      when[ready_to_change] = 0;
      recomd[student] = 1;
      when[student] = idx;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int student;
    cin >> student;

    solution(i, student);
  }

  for (int i = 1; i <= MAX; i++) {
    if (recomd[i] > 0) {
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}