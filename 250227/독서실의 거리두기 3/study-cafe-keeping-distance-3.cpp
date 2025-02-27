#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string seats;
int max_dist, min_dist = 100000;
int max_s, max_e, ans;

int main() {
    cin >> N;
    cin >> seats;

    // Please write your code here.
    int s = 0;
    for(int i = 1; i < N; i++){
        if(seats[i] == '1'){

            if(max_dist < i - s){
                max_s = s;
                max_e = i;
                max_dist = i - s;
            }

            min_dist = min(min_dist, i - s);
            s = i;
        }
    }

    for(int i = max_s + 1; i < max_e; i++){
        ans = max(ans, min(i - max_s, max_e - i));
    }

    cout << min(ans, min_dist);
    return 0;
}