#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> r;

int main() {
    cin >> n;

    // Write your code here!
    while(n / 2){
        r.push(n % 2);
        n = n / 2;
    }

    cout << 1;
    while(!r.empty()){
        cout << r.top();
        r.pop();
    }

    return 0;
}