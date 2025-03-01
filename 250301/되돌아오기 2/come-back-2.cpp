#include <iostream>
using namespace std;

string dir;
int x, y, dir_num;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    // Please write your code here.
    cin >> dir;

    for(int i = 0; i < dir.size(); i++){
        if(dir[i] == 'L'){ // 왼쪽 90도
            dir_num = (dir_num + 3) % 4;

        } else if(dir[i] == 'R'){ // 오른쪽 90도
            dir_num = (dir_num + 1) % 4;
            
        } else{
            x = x + dx[dir_num];
            y = y + dy[dir_num];
        }

        if(x == 0 && y == 0){
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}