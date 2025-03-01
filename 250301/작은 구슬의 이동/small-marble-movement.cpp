#include <iostream>
#include <unordered_map>
using namespace std;

int n, t, cnt;
int r, c, now;
char d;
unordered_map<char, int> direct;

int dx[4] = {1, 0, -1, 0}; // 우 하 좌 상
int dy[4] = {0, 1, 0, -1};

int main() {
    // Please write your code here.
    direct['R'] = 0;
    direct['D'] = 1;
    direct['L'] = 2;
    direct['U'] = 3;

    cin >> n >> t;
    // 구슬이 벽에 부닺히면 움직이는 방향이 반대로 뒤집힘
    // 방향을 바꾸는데는 1만큼 소요됨
    cin >> r >> c;
    cin >> d;
    now = direct[d];

    while(cnt < t){
        cnt++;

        int nr = r + dy[now];
        int nc = c + dx[now];

        if(nr < 1 || nr > n || nc < 1 || nc > n){ // 방향만 변화
            now = (now + 2) % 4;
        }
        else{ // 이동
            r = nr;
            c = nc;
        }
    }

    cout << r << " " << c;

    return 0;
}