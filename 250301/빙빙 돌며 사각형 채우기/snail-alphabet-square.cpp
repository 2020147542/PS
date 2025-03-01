#include <iostream>
using namespace std;

int n, m;
int dir_num, r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char alpha = 'A';
char arr[111][111];

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < n * m; i++){
        arr[r][c] = alpha + i % 26;

        int nr = r + dy[dir_num];
        int nc = c + dx[dir_num];
        if(arr[nr][nc] != 0 || nr >= n || nr < 0 || nc >= m || nc < 0){
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