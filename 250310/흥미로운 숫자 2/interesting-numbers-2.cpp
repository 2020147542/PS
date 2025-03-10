#include <iostream>
#include <vector>
using namespace std;

int x, y;
vector<int> arr;

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