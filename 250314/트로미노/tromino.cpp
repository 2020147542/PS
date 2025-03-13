#include <iostream>
#include <climits>
using namespace std;

int n, m, max_val = INT_MIN;
int arr[210][210];
int dx[6][2] = {{0, 1}, {0, -1}, {-1, 0}, {0, 1}, {1, 2}, {0, 0}};
int dy[6][2] = {{-1, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, 0}, {1, 2}};

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 6; k++){
                
                int sum = arr[i][j];
                bool isIncluded = true;
                for(int t = 0; t < 2; t++){
                    int nx = j + dx[k][t];
                    int ny = i + dy[k][t];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        isIncluded = false;
                        break;
                    }
                    sum += arr[ny][nx];
                }
                
                if(isIncluded){
                    max_val = max(max_val, sum);
                }
            }
        }
    }

    cout << max_val;
    return 0;
}