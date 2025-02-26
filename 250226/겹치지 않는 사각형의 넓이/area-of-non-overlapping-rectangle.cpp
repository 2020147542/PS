#include <iostream>

using namespace std;

int sum;
int x1[3], y1[3];
int x2[3], y2[3];
int grid[2111][2111];

int main() {
    // 좌측 최하단 ~ 우측 최상단
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];

    for(int j = y1[0] + 1000; j < y2[0] + 1000; j++)  {
        for(int i = x1[0] + 1000; i < x2[0] + 1000; i++){
            grid[j][i] = 1;
        }
    }

    for(int j = y1[1] + 1000; j < y2[1] + 1000; j++)  {
        for(int i = x1[1] + 1000; i < x2[1] + 1000; i++){
            grid[j][i] = 1;
        }
    }

    for(int j = y1[2] + 1000; j < y2[2] + 1000; j++)  {
        for(int i = x1[2] + 1000; i < x2[2] + 1000; i++){
            grid[j][i] = 0;
        }
    }

    for(int i = 0; i < 2111; i++){
        for(int j = 0; j < 2111; j++){
            sum += grid[i][j];
        }
    }

    cout << sum;

    return 0;
}