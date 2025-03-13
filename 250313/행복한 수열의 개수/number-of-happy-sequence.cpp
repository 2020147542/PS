#include <iostream>
using namespace std;

int n, m, total_cnt;
int grid[111][111]; 

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    // 1. 가로 
    for(int i = 0; i < n; i++){
        int now = grid[i][0];
        int cnt = 1;

        for(int j = 1; j < n; j++){
            if(now == grid[i][j]){
                cnt++;
            } else{
                now = grid[i][j];
                cnt = 1;
            }

            if(cnt >= m){
                total_cnt++;
                break;
            }
        }
    }

    // 2. 세로
    for(int j = 0; j < n; j++){
        int now = grid[0][j];
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(now == grid[i][j]){
                cnt++;
            } else{
                now = grid[i][j];
                cnt = 1;
            }

            if(cnt >= m){
                total_cnt++;
                break;
            }
        }
    }

    cout << total_cnt;

    return 0;
}