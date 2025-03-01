#include <iostream>
using namespace std;

int n, m;
int dir_num, r, c;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[111][111];

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 1; i <= n * m; i++){
        arr[r][c] = i;

        // 방향 변화
        int nr = r + dy[dir_num];
        int nc = c + dx[dir_num];
        if(arr[nr][nc] != 0 || nr < 0 || nr >= n || nc < 0 || nc >= m) {
            dir_num = (dir_num + 1) % 4;
        }

        // 이동
        r = r + dy[dir_num];
        c = c + dx[dir_num];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}