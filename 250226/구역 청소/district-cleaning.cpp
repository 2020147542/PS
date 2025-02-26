#include <iostream>
using namespace std;

int a, b, c, d, sum;
int line[111];

int main(){
    cin >> a >> b >> c >> d;

    for(int i = a; i < b; i++){
        line[i] = 1;
    }

    for(int i = c; i < d; i++){
        line[i] = 1;
    }

    for(int i = 0; i < 111; i++){
        sum += line[i];
    }

    cout << sum;

    return 0;
}