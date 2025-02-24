#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> r;

int main() {
    cin >> n;

    // Write your code here!
    while(true){
        r.push(n % 2);

        if(n <= 1) break;
        n = n / 2;
    }

    while(!r.empty()){
        cout << r.top();
        r.pop();
    }

    return 0;
}