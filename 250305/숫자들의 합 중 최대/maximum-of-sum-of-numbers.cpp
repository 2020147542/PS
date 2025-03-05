#include <iostream>
#include <string>
using namespace std;

int x, y, ans;

int main() {
    // Please write your code here.
    cin >> x >> y;

    for(int i = x; i <= y; i++){
        int now = i;
        int sum = 0;

        while(now){
            sum += (now % 10); 
            now /= 10;
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}