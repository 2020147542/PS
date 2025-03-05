#include <iostream>
#include <climits>
using namespace std;

int n, ans = INT_MAX;
int x[111];
int y[111];
int curx, cury;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    // 모든 경우에
    // 1, n을 제외하고 체크포인트 하나를 건너 뛰어서 완주하려고 할때
    for(int i = 1; i < n-1; i++){ // n
        // 할거 하기
        // 거리의 최소 구하기 // n-1
        int res = 0;
        curx = x[0];
        cury = y[0];
        for(int j = 1; j < n; j++){
            if(i == j) continue;
            res = res + abs(curx - x[j]) + abs(cury - y[j]);
            curx = x[j];
            cury = y[j];
        }
        ans = min(ans, res);
    }

    cout << ans;
    
    return 0;
}