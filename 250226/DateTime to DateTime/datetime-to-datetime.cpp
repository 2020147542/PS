#include <iostream>
using namespace std;

int a, b, c, ans;
int d = 11, h = 11, m = 11;

int main(){
    cin >> a >> b >> c;

    if(a == 11 && b < 11 ||  a == 11 && b == 11 && c < 11) {
        cout << -1;
        return 0;
    }

    while(a != d || b != h || c != m){
        m++;
        ans++;

        if(m == 60){
            h++;
            m = 0;

            if(h == 24){
                d++;
                h = 0;
            }
        }
    }

    cout << ans;
    return 0;
}