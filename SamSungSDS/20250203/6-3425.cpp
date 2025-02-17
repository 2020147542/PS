#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

vector<string> comnds;
int outcome;
const int MAX = 1000000000;

bool solution(int num) {
  stack<ll> goStack;
  goStack.push(num);

  for (int i = 0; i < comnds.size(); i++) {
    string comnd = comnds[i];

    if (comnd == "NUM") {
      goStack.push(stoi(comnds[++i]));

    } else if (comnd != "END") {
      if (goStack.empty()) return false;
      ll first = goStack.top();

      if (comnd == "POP") {
        goStack.pop();

      } else if (comnd == "INV") {
        goStack.pop();
        goStack.push(-first);

      } else if (comnd == "DUP") {
        goStack.push(first);

      } else {
        if (goStack.size() < 2) return false;
        goStack.pop();

        ll second = goStack.top();
        goStack.pop();

        if (comnd == "SWP") {
          goStack.push(first);
          goStack.push(second);

        } else {
          ll result;
          if (comnd == "ADD") {
            result = second + first;

          } else if (comnd == "SUB") {
            result = second - first;

          } else if (comnd == "MUL") {
            result = second * first;

          } else if (comnd == "DIV") {
            if (first == 0) return false;
            result = abs(second) / abs(first);
            if (first * second < 0) result = -result;

          } else if (comnd == "MOD") {
            if (first == 0) return false;
            result = abs(second) % abs(first);
            if (second < 0) result = -result;
          }

          if (abs(result) > MAX) return false;
          goStack.push(result);
        }
      }
    }
  }

  outcome = goStack.top();
  return goStack.size() == 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string command;
  int total_num, num;

  while (true) {
    cin >> command;

    if (command == "QUIT") return 0;
    comnds.push_back(command);

    if (command == "END") {
      cin >> total_num;

      for (int i = 0; i < total_num; i++) {
        cin >> num;

        if (solution(num)) {
          cout << outcome << '\n';
        } else {
          cout << "ERROR" << '\n';
        }
      }
      cout << '\n';
      comnds.clear();
    }
  }

  return 0;
}
