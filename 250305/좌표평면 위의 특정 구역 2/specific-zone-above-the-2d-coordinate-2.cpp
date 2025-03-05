#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pir;

int n, ans = 10000000000;
vector<pir> spot;

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        spot.push_back(pir(x, y));
    }

    // 각각의 점을 제외한 모든 경우를 고려함
    for(int i = 0; i < n; i++){
        // i번 점이 빠졌다고 할때, 그외 모든 점들에 대해 커버하는 최소 직사각형 넓이 구하기
        int Y_MAX = -1000000, Y_MIN = 1000000;
        int X_MAX = -1000000, X_MIN = 1000000;

        for(int j = 0; j < n; j++){
            if(i == j) continue;

            int x = spot[j].first;
            int y = spot[j].second;

            X_MIN = min(X_MIN, x);
            X_MAX = max(X_MAX, x);
            Y_MIN = min(Y_MIN, y);
            Y_MAX = max(Y_MAX, y);
        }

        int res = (X_MAX - X_MIN) * (Y_MAX - Y_MIN);
        ans = min(ans, res);   
    }

    cout << ans;
    return 0;
}