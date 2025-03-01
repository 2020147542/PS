#include <iostream>
using namespace std;

int n;
int r, c, dir_num;
int arr[111][111];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    // Please write your code here.
    cin >> n;
    r = n-1;
    c = n-1;
    
    for(int i = n*n; i >= 1; i--){
        arr[r][c] = i;

        int nr = r + dy[dir_num];
        int nc = c + dx[dir_num];
        if(arr[nr][nc] != 0 || nr >= n || nr < 0 || nc >= n || nc < 0){
            dir_num = (dir_num + 1) % 4;
        }

        r = r + dy[dir_num];
        c = c + dx[dir_num];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}