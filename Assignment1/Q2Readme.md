
# Echoes of the Blood Moon

## Problem Description

Tanjiro finds himself climbing Spider Mountain, where he must face demonic echoes of the past. Your task is to help him find the **longest chain of strictly increasing demonic echoes** 

- **Input**: An array of echo strengths  
- **Output**: The length of the longest strictly increasing subsequence  
- **Example**:  
  Input: `[3, 1, 5, 2, 6, 4, 9]`  
  Output: `4`

---

## My Efforts and Approaches

### First Try: Simple Recursion

I began with a naive recursive solution. From each index, I tried to recursively find the longest path by checking all possible increasing moves.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> echoes;
int n;

int findPath(int pos) {
    int maxLen = 1;
    for (int next = pos + 1; next < n; next++) {
        if (echoes[next] > echoes[pos]) {
            maxLen = max(maxLen, 1 + findPath(next));
        }
    }
    return maxLen;
}

int solve() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, findPath(i));
    }
    return result;
}

int main() {
    cin >> n;
    echoes.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> echoes[i];
    }
    cout << solve() << endl;
    return 0;
}
```

---

### Third Try: Brute Force Iteration

I also tried a simple iterative method, checking possible subsequences from each index. This was not optimal, but a good learning step.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> echoes(n);

    for (int i = 0; i < n; i++) {
        cin >> echoes[i];
    }

    int maxLength = 1;

    for (int start = 0; start < n; start++) {
        int currentLength = 1;
        int lastValue = echoes[start];

        for (int pos = start + 1; pos < n; pos++) {
            if (echoes[pos] > lastValue) {
                currentLength++;
                lastValue = echoes[pos];
            }
        }

        maxLength = max(maxLength, currentLength);
    }

    cout << maxLength << endl;
    return 0;
}
```

---

### Final Try: Optimal Binary Search Method – O(n log n)

Finally, I implemented the optimal method using **Patience Sorting** technique with `lower_bound`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestEchoChainOptimal(vector<int>& echo) {
    vector<int> tails;

    for (int num : echo) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }

    return tails.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> echo(n);

    for (int i = 0; i < n; i++) {
        cin >> echo[i];
    }

    cout << longestEchoChainOptimal(echo) << endl;
    return 0;
}
```

While this is the fastest method, I chose not to use it as my **main solution**, as I preferred the recursion-based one for clarity and theme alignment.

---

## Challenges I Faced

### Couldn't Achieve Linear Time

At first, I believed I could solve this in O(n) time, but after multiple failed attempts, I learned that the LIS problem has a lower bound of O(n log n). This realization was an important learning step.

### Struggled with Recursion Initially

Early on, my recursive solution was very slow and inefficient. Once I understood the nature of overlapping subproblems, I realized why additional optimizations might help, but chose not to apply them in this case for the sake of clarity.

---

## My Final Choice

I selected the **simple recursive approach** as my final solution. Here's why:
- Easy to understand and debug
- Suitable for input sizes (n ≤ 1000)
- Fits the story-driven recursive exploration theme
- A good balance between performance and readability

---

## What I Learned

- Multiple approaches to solving the same problem
- Trade-offs between speed (binary search) and clarity (recursion)
- Importance of thinking through performance issues
- Some problems can’t be optimized beyond theoretical limits

