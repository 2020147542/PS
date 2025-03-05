#include <iostream>
#include <string>
using namespace std;

int x, y, ans;

int main() {
    // Please write your code here.
    cin >> x >> y;

    for(int i = x; i <= y; i++){
        string a = to_string(i);
        int sum = 0;
        for(char ele: a){
            sum += (ele - '0');
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}