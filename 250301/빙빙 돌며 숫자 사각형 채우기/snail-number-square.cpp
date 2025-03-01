#include <iostream>
using namespace std;

int n, m;
int r, c;
int i = 1, dir_num;
int arr[111][111];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    // Please write your code here.
    cin >> n >> m;

    while(i <= n * m){
        // 1. 현재 위치 값 입력
        arr[r][c] = i++;

        int nr = r + dy[dir_num];
        int nc = c + dx[dir_num];

        if(arr[nr][nc] != 0 || nr < 0 || nr >= n || nc < 0 || nc >= m){ 
            dir_num = (dir_num + 1) % 4;
        }

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