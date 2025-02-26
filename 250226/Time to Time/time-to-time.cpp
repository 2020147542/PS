#include <iostream>

using namespace std;

int a, b, c, d;
int cnt;

int main() {
    cin >> a >> b >> c >> d;



    while(a != c || b != d){
        
        b++;
        cnt++;

        if(b == 60){
            a++;
            b = 0;
        }

    }

    cout << cnt << endl;

    return 0;
}