#include <iostream>
using namespace std;

int x, cnt = 1;
int backDist[11111];
int speed = 1, dist = 1;
bool timeToStop;

int main(){

    cin >> x;
    
    for(int i = 1; i <= x; i++){
        backDist[i] = backDist[i-1] + i;
    }

    while(dist < x){ // 1초에 한번씩 확인

        if(backDist[speed + 1] <= x - dist){
            speed++;
        } else if(speed >= 2){
            speed--;
        }

        dist += speed;
        cnt++;
    }

    cout << cnt;
    
    return 0;
}