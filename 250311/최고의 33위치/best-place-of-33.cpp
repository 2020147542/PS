#include <iostream>
#include <climits>
using namespace std;

int n, res = INT_MIN;
int arr[22][22];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < n-2; j++){

            // 3*3
            int sum = 0;
            for(int r = i; r < i + 3; r++){
                for(int c = j; c < j + 3; c++){
                    sum += arr[r][c];
                }
            }   

            res = max(res, sum);
        }
    }

    cout << res;
    return 0;
}