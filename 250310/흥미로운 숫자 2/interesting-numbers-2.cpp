#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y;
vector<int> arr;

bool isInteresting(int num){
    vector<int> digits(10, 0);
    
    int n = 0;
    while(num){
        int now = num % 10;
        digits[now]++;
        n++;
        num /= 10;
    }
    
    for(int i = 0; i < 10; i++){
        if(digits[i] == n-1) return true;
    }
    
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