#include <iostream>
using namespace std;

int n;
int arr[111][111];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int ans;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;

            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                
                if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
                if(arr[ny][nx]) cnt++;
            }
            if(cnt >= 3) ans++;
        }
    }

    cout << ans;
    
    return 0;
}