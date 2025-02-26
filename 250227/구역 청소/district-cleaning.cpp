#include <iostream>
using namespace std;

int a, b, c, d, sum;
int line[111];

int main(){
    cin >> a >> b >> c >> d;

    if(b < c || d < a){ // 겹치지 않을 경우
        sum = (b-a) + (d-c);
    }else{
        // 1. 한쪽이 다 포괄할 경우
        if(a <= c && d <= b){
            sum = (b - a);
        } else if(c <= a && b <= d){
            sum = (d - a);
        } else{
            // 2. 중간만 겹칠 경우
            if(a <= c && b >= c){ // a c b d
                sum = (c - a) + (b - c) + (d - b);
            } else if(c <= a && d >= a){ // c a d b
                sum = (a - c) + (d - a) + (b - d); 
            }
        }
    }

    cout << sum;

    return 0;
}