#include <iostream>
#include <algorithm>
using namespace std;

int a, b, x, y;
int ans;

int main() {
    cin >> a >> b >> x >> y;

    // Please write your code here.
    ans = abs(a - b);

    int max_p = max(a, b);
    int min_p = min(a, b);
    int max_t = max(x, y);
    int min_t = min(x, y);

    ans = min(ans, abs(min_t - min_p) + abs(max_t - max_p));

    cout << ans;
    return 0;
}