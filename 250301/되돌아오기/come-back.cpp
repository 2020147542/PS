#include <iostream>
#include <unordered_map>
using namespace std;

int n;
int x, y, dist, ans;
char direction;
int dx[4] = {1, 0, -1, 0}; // 동남서북
int dy[4] = {0, -1, 0, 1};
unordered_map<char, int> direct;

int main() {
    // Please write your code here.
    cin >> n;

    direct['W'] = 2;
    direct['S'] = 1;
    direct['N'] = 3;
    direct['E'] = 0;

    for(int i = 0; i < n; i++){
        cin >> direction >> dist;

        for(int i = 1; i <= dist; i++){
            x = x + dx[direct[direction]];
            y = y + dy[direct[direction]];
            ans ++;

            if(x == 0 && y == 0){
                cout << ans;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}