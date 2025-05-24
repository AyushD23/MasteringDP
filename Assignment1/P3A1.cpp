#include <bits/stdc++.h>
using namespace std;

void sortArr(vector<int>& arr, int max) {
    int len = arr.size();

    // This list counts how many times each number appears
    // Takes O(n) time because we look at each number once
    vector<int> cnt(max + 1, 0);

    // This will store the final sorted list
    vector<int> out(len);

    // Step 1: Count how many times each number is present
    // One loop over the array => O(n) time
    for (int i = 0; i < len; i++) {
        cnt[arr[i]]++;
    }

    // Step 2: Add up counts to know the positions of each number
    // One loop from 1 to max => O(k) time (k is the biggest number in array)
    for (int i = 1; i <= max; i++) {
        cnt[i] += cnt[i - 1];
    }

    // Step 3: Place each number in the correct position
    // One more loop over the array (from end) => O(n) time
    for (int i = len - 1; i >= 0; i--) {
        out[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }

    // Step 4: Copy sorted numbers back to original array
    // One final loop over array => O(n) time
    for (int i = 0; i < len; i++) {
        arr[i] = out[i];
    }
}

// Total time:
// O(n) to count
// + O(k) to calculate positions
// + O(n) to place values
// + O(n) to copy back
// => O(n + k) time
// If k (biggest number) is not much larger than n, this is O(n) overall

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
