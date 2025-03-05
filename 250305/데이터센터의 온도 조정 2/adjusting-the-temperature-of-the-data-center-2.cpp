#include <iostream>
#include <climits>
using namespace std;

int n, c, g, h;
int MIN_T = INT_MAX, MAX_T = INT_MIN;
int ta[1111];
int tb[1111];
int ans = INT_MIN;

int main() {
    // Please write your code here.

    cin >> n >> c >> g >> h;
    for(int i = 0; i < n; i++){
        cin >> ta[i] >> tb[i];

        MIN_T = min(MIN_T, ta[i]);
        MAX_T = max(MAX_T, tb[i]);
    }

    // 데이터 센서 안의 최고 작업량 출력하기
    // t < ta - c
    // ta <= t <= tb - g
    // tb < t - h
    for(int i = MIN_T; i <= MAX_T; i++){ // 1000
        int sum = 0;
        for(int k = 0; k < n; k++){ // 1000
            if(i < ta[k]) sum += c;
            else if(i > tb[k]) sum += h;
            else sum += g;
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}