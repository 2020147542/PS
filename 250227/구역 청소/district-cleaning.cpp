#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;
int line[111];

int main(){
    cin >> a >> b >> c >> d;

    cout << max(b, d) - min(a, c);
    return 0;
}