#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> dirs;
int n, x, y;
char dir;
int dist;

// 오른쪽 아래 왼쪽 위
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    // Please write your code here.
    cin >> n;

    dirs['W'] = 2;
    dirs['S'] = 1;
    dirs['N'] = 3;
    dirs['E'] = 0;

    for(int i = 0; i < n; i++){
        cin >> dir >> dist;

        x += dist * dx[dirs[dir]];
        y += dist * dy[dirs[dir]];
    }

    cout << x << " " << y;

    return 0;
}