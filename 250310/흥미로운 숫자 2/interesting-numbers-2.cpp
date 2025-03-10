#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y;
vector<int> arr;

bool isInteresting(int num){
    vector<int> digits;
    
    while(num){
        int now = num % 10;
        digits.push_back(now);
        num /= 10;
    }
    
    int diff = 0;
    int n = digits.size();
    for(int i = 0; i < n; i++){
        int cnt = count(digits.begin(), digits.end(), digits[i]);
        if(cnt != n-1) diff++;
    }

    if(diff == 1) return true;
    return false;
}

int main() {
    // Please write your code here.
    cin >> x >> y;

    for(int i = x; i <= y; i++){
        if(isInteresting(i)){
            arr.push_back(i);
        }
    }

    cout << arr.size();
    return 0;
} 