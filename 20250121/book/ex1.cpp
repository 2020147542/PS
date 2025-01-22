/*
  정수 N을 입력받아 1부터 N까지의 숫자 중에서 합이 10이 되는 조합을 배열로
  반환하는 solution 함수를 작성해라
*/

#include <iostream>
#include <vector>
#define K 10

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backTracking(int N, int start, int sum) {
  if (sum == K) {
    results.push_back(selected_nums);
    return;
  }

  for (int i = start; i <= N; i++) {
    if (sum + i <= K) {
      selected_nums.push_back(i);
      backTracking(N, i + 1, sum + i);
      selected_nums.pop_back();
    }
  }
}

vector<vector<int>> solution(int N) {
  backTracking(N, 1, 0);
  return results;
}

int main() {
  int N;
  cin >> N;

  for (auto comb : solution(N)) {
    for (int ele : comb) {
      cout << ele << ", ";
    }
    cout << endl;
  }

  return 0;
}