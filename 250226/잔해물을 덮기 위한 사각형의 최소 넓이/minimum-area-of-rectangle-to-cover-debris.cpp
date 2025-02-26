#include <iostream>
#include <algorithm>
using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];
int grid[2111][2111];
int min_x = 10000, max_x;
int min_y = 10000, max_y;

int main() {

    // 좌측 하단 ~ 우측 상단
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    for(int i = x1[0] + 1000; i < x2[0] + 1000; i++){
        for(int j = y1[0] + 1000; j < y2[0] + 1000; j++){
            grid[i][j] = 1;
        }
    }

    for(int i = x1[1] + 1000; i < x2[1] + 1000; i++){
        for(int j = y1[1] + 1000; j < y2[1] + 1000; j++){
            grid[i][j] = 0;
        }
    }

    for(int i = 0; i < 2111; i++){
        for(int j = 0; j < 2111; j++){
            if(grid[i][j]){
                min_x = min(min_x, i);
                max_x = max(max_x, i + 1);

                min_y = min(min_y, j);
                max_y = max(max_y, j + 1);
            }
        }
    }

    cout << (max_x - min_x)  * (max_y - min_y);
    return 0;
}