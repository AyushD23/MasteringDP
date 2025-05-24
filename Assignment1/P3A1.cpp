#include <bits/stdc++.h>
using namespace std;

void sortArr(vector<int>& arr, int max) {
    int len = arr.size();
    vector<int> cnt(max + 1, 0);
    vector<int> out(len);
    
    for (int i = 0; i < len; i++) {
        cnt[arr[i]] = cnt[arr[i]] + 1;
    }
    
    for (int i = 1; i <= max; i++) {
        cnt[i] = cnt[i] + cnt[i - 1];
    }
    
    for (int i = len - 1; i >= 0; i--) {
        out[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]] = cnt[arr[i]] - 1;
    }
    
    for (int i = 0; i < len; i++) {
        arr[i] = out[i];
    }
}

int main() {
    vector<int> lst = {4, 2, 2, 8, 3, 3, 1};
    int maxVal = 8;
    
    cout << "Before sort: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;
    
    sortArr(lst, maxVal);
    
    cout << "After sort: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
