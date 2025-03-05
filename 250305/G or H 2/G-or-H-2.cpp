#include <iostream>
#include <climits>
using namespace std;

int n, ans = INT_MIN;
int cnt_g[111];
int cnt_h[111];

int main() {
    // Please write your code here.

    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++){
        int x;
        char y;
        cin >> x >> y;

        if(y == 'G') cnt_g[x] = 1;
        else cnt_h[x] = 1;
    }

    // 모든 경우에
    // 가능한 모든 범위에서
    for(int i = 0; i <= 100; i++){
        if(cnt_g[i] || cnt_h[i]){
            
            // 할걸 하자
            // g와 h가 정확하게 같은 개수가 나오는 경우를 구해라
            int g = 0;
            int h = 0;
            for(int j = i; j <= 100; j++){
                g += cnt_g[j];
                h += cnt_h[j];

                if((cnt_g[j] || cnt_h[j]) && g == h){
                    ans = max(ans, j - i);
                }
            }
        }
    }

    cout << ans;
    return 0;
}