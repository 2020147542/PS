#include <iostream>
#include <string>
using namespace std;

string direct;
int dx[4] = {1, 0, -1, 0}; // 우 하 좌 상
int dy[4] = {0, -1, 0, 1}; 
int x, y, now = 3;

int main() {
    
    // Please write your code here.
    cin >> direct;

    for(int i = 0; i < direct.size(); i++){

        if(direct[i] == 'F'){ // 한칸씩 이동
            x += dx[now];
            y += dy[now];
        } else{
            // 방향만 변경
            if(direct[i] == 'L') now = (now + 3) % 4;
            else now = (now + 1) % 4;
        }
    }

    cout << x << " " << y;

    return 0;
}