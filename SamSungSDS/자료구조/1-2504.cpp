#include <iostream>
#include <stack>
using namespace std;

char words[31];
stack<char> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> words;

  int ans = 0, temp = 1;
  for (int i = 0; i < 31; i++) {
    char c = words[i];
    if (c == '\0') break;

    if (c == '(') {
      temp *= 2;
      st.push(c);
    } else if (c == '[') {
      temp *= 3;
      st.push(c);
    } else if (c == ')') {
      if (st.empty() || st.top() != '(') {
        ans = 0;
        break;

      } else if (words[i - 1] == '(') {  // 기저
        ans += temp;
      }

      temp /= 2;
      st.pop();
    } else if (c == ']') {
      if (st.empty() || st.top() != '[') {
        ans = 0;
        break;

      } else if (words[i - 1] == '[') {  // 기저
        ans += temp;
      }

      temp /= 3;
      st.pop();
    }
  }

  if (!st.empty()) ans = 0;
  cout << ans << '\n';

  return 0;
}