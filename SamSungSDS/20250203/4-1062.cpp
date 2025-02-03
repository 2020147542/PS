#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K, max_count = 0;
vector<vector<bool>> words;
vector<bool> choices(26);

void back_tracking(int i, int cnt) {
  if (cnt == K) {  // k개를 선택한 경우
    int count = N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 26; j++) {
        if (words[i][j] && !choices[j]) {
          count--;
          break;
        }
      }
    }

    max_count = count > max_count ? count : max_count;
    return;
  }

  if (i >= 26) return;

  // 선택 안한 경우
  back_tracking(i + 1, cnt);

  // 5개중 하나를 선택한 경우 제외 = 무조건 선택한 것으로 이미 반영되어 있음
  if (choices[i]) return;

  // 그외 선택한 경우
  choices[i] = true;
  back_tracking(i + 1, cnt + 1);
  choices[i] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  words.resize(N, vector<bool>(26));

  choices['a' - 'a'] = true;
  choices['n' - 'a'] = true;
  choices['t' - 'a'] = true;
  choices['i' - 'a'] = true;
  choices['c' - 'a'] = true;

  for (int i = 0; i < N; i++) {
    string a;
    cin >> a;

    for (int j = 0; j < a.size(); j++) {
      words[i][a[j] - 'a'] = true;
    }
  }

  if (K - 5 < 0) {
    cout << 0 << '\n';
    return 0;
  }

  back_tracking(0, 5);
  cout << max_count << '\n';

  return 0;
}