#include <iostream>
#include <climits>
using namespace std;

int n, k;
int grid[510][510];
int sum[510][510];
int max_val = INT_MIN;

int main() {
    // Please write your code here.
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
        }
    }

    for(int i = k; i <= n; i++){
        for(int j = k; j <= n; j++){
            int value = sum[i][j] - sum[i][j-k] - sum[i-k][j] + grid[i-k][j-k];
            max_val = max(max_val, value);
        }
    }

    cout << max_val;
    return 0;
}