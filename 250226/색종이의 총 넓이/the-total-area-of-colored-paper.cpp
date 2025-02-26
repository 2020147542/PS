#include <iostream>

using namespace std;

int N, sum;
int x[100], y[100];
int grid[222][222];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];

        for(int r = y[i] + 100; r < y[i] + 100 + 8; r++){
            for(int c = x[i] + 100; c < x[i] + 100 + 8; c++){
                grid[r][c] = 1;
            }
        }
    }

    for(int i = 0; i < 222; i++){
        for(int j = 0; j < 222; j++){
            sum += grid[i][j];
        }
    }

    cout << sum;
    return 0;
}