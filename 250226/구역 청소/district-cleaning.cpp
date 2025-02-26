#include <iostream>
using namespace std;

int a, b, c, d, sum;
int line[111];

int main(){
    cin >> a >> b >> c >> d;

    if(b < c || d < a){
        sum = (b-a) + (d-c);
    }
    else if(d >= a){
        sum = (a-c) + (d-a) + (b-d);
    } 
    else if(b >= c){
        sum = (c-a) + (d-b) + (b-c);
    }

    cout << sum;
    return 0;
}