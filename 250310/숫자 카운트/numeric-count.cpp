#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> a;

void find(int b, int cnt1, int cnt2){
    int digit[3] = {b/100, (b/10)%10, b% 10};
    unordered_set<int> now = {b/100, (b/10)%10, b% 10};
    vector<int> remain;

    for(int num : a){
        int i = num / 100;
        int j = (num / 10) % 10;
        int k = num % 10;

        int c1 = 0, c2 = 0;
        if(i == digit[0]) c1++;
        if(j == digit[1]) c1++;
        if(k == digit[2]) c1++;

        if(i != digit[0] && now.count(i)) c2++;
        if(j != digit[1] && now.count(j)) c2++;
        if(k != digit[2] && now.count(k)) c2++;
        
        if(c1 == cnt1 && c2 == cnt2){
            remain.push_back(num);
        }
    }

    a = remain;
}

int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i == j) continue;
            for(int k = 1; k <= 9; k++){
                if(i == k || j == k) continue;

                a.push_back(i * 100 + j * 10 + k);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int b, cnt1, cnt2;
        cin >> b >> cnt1 >> cnt2;

        find(b, cnt1, cnt2);
    }

    cout << a.size();
    return 0;
}