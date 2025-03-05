#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, ans = INT_MIN;
int people[111];
int cnt_g[111];
int cnt_h[111];

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        char y;
        cin >> people[i] >> y;

        if(y == 'G') cnt_g[people[i]] = 1;
        else cnt_h[people[i]] = 1;
    }

    sort(people, people + n);

    // 모든 경우에
    // 가능한 모든 범위에서
    for(int i = 0; i < n; i++){
        int start = people[i];

        // 할걸 하자
        // g와 h가 정확하게 같은 개수가 나오는 경우를 구해라
        int g = 0;
        int h = 0;
        for(int j = i; j < n; j++){
            int end = people[j];
            
            g += cnt_g[end];
            h += cnt_h[end];

            if((g == h) || (g && !h) || (h && !g)){
                ans = max(ans, end - start);
            }
        }
    }

    cout << ans;
    return 0;
}