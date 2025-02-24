#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans;
int A[100], B[100];
int block[101];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }

    // Write your code here!
    for (int i = 0; i < K; i++) {
        for(int j = A[i]; j <= B[i]; j++){
            ans = max(ans, ++block[j]);
        }
    }

    cout << ans << "\n";

    return 0;
}