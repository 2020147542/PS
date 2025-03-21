#include <iostream>
#include <climits>
using namespace std;

int n;
int max_val = INT_MIN;
int grid[310][310];
int sum[310][310];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
        }
    }

    for(int h = 1; h <= n; h++){
        for(int w = 1; w <= n; w++){
            
            for(int i = h; i <= n; i++){
                for(int j = w; j <= n; j++){
                    max_val = max(max_val, sum[i][j] - sum[i-h][j] - sum[i][j-w] + sum[i-h][j-w]);
                }
            }

        }
    }

    cout << max_val;

    return 0;
}