#include <iostream>
using namespace std;

int a, b, c, d, sum;
int line[111];

int main(){
    cin >> a >> b >> c >> d;

    if(b < c || d < a){ // 겹치지 않을 경우
        sum = (b-a) + (d-c);
    }
    else if(d >= a && b >= d){
        // 겹치는데 순서: c a d b
        sum = (a-c) + (d-a) + (b-d);
    } 
    else if(b >= c && d >= b){
        // 겹치는데 순서: a c b d
        sum = (c-a) + (b-c) + (d - b);
    }

    cout << sum;

    return 0;
}