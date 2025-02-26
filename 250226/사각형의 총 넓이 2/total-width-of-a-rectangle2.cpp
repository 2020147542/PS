#include <iostream>

using namespace std;

int N, sum;
int x1[10], y1[10];
int x2[10], y2[10];
int grid[210][210];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        for(int x = x1[i] + 100; x < x2[i] + 100; x++){
            for(int y = y1[i] + 100; y < y2[i] + 100; y++){
                grid[y][x] = 1;
            }
        }
    }

    for(int i = 0; i < 210; i++){
        for(int j = 0; j < 210; j++){
            sum += grid[i][j];
        }
    }

    cout << sum;

    return 0;
}