#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string line;
vector<vector<int>> numbers;
int ans = INT_MIN, cnt;

int main() {
    // Please write your code here.
    for(int a = 1; a <= 4; a++){
        for(int b = 1; b <= 4; b++){
            for(int c = 1; c <= 4; c++){
                for(int d = 1; d <= 4; d++){
                    for(int e = 1; e <= 4; e++){
                        for(int f = 1; f <= 4; f++){
                            numbers.push_back({a, b, c, d, e, f});
                        }
                    }
                }
            }
        }
    }

    cin >> line;
    for(int j = 0; j < numbers.size(); j++){
        int res = numbers[j][line[0]-'a'];

        for(int i = 1; i < line.size(); i++){
            if(line[i] == '*'){
                res *= numbers[j][line[i+1]-'a'];
            }else if(line[i] == '-'){
                res -= numbers[j][line[i+1]-'a'];
            }else if(line[i] == '+'){
                res += numbers[j][line[i+1]-'a'];
            }

        }
        
        ans = max(ans, res);
    }

    if(ans == INT_MIN){
        cout << 4;
    }else{
        cout << ans;
    }
    
    
    return 0;
}