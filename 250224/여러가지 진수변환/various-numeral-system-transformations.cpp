#include <iostream>
#include <stack>

using namespace std;

int N, B;
stack<int> ans;

int main() {
    cin >> N >> B;

    while(true){
        ans.push(N % B);

        if(N < B) break;
        N /= B;
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }

    return 0;
}