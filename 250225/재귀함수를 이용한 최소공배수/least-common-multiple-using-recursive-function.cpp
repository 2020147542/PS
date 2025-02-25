#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int x[10];
int r[4] = {2, 3, 5, 7};

int gcd(int a, int b) {
    if(a == 1 || b == 1) return a * b;

    for(int i = 0; i < 4; i++){
        if ((a % r[i] == 0) && (b % r[i] == 0)) {
            return r[i] * gcd(a / r[i], b / r[i]);
        }
    }

    return a * b;
}

int main() {
    // Please write your code here.
    cin >> n;

    ans = 1;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        ans = gcd(x[i], ans);
    }

    cout << ans << "\n";

    return 0;
}