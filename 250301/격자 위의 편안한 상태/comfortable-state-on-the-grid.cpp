#include <iostream>
using namespace std;

int n, m;
int r, c, ans;
int dx[4] = {1, 0, -1, 0}; // 우 하 좌 상
int dy[4] = {0, 1, 0, -1};
int arr[111][111];

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> r >> c;
        arr[r][c] = 1;

        int cnt = 0;
        for(int j = 0; j < 4; j++){
            int nr = r + dy[j];
            int nc = c + dx[j];

            if(nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
            if(arr[nr][nc]) cnt++;
        }
        
        cout << (cnt == 3) << "\n";
    }

    return 0;
}