#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for(int i = 0; i < 2; i++){
        int s, e;
        cin >> s >> e;

        vector<int> temp;
        for(int j = s - 1; j <= e - 1; j++){
            arr[j] = 0;
        }
        
        for(int j = 0; j < n; j++){
            if(arr[j]) {
                temp.push_back(arr[j]);
            }
        }

        arr.clear();
        swap(arr, temp);
    }

    cout << arr.size() << "\n";
    for(int ele: arr){
        cout << ele << "\n";
    }
    
    return 0;
}