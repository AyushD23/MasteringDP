#include <bits/stdc++.h>
using namespace std;

vector<int> echoes;
int n;

int buildPath(int start, int current, int length) {
    int maxLen = length;
    
    for (int next = current + 1; next < n; next++) {
        if (echoes[next] > echoes[current]) {
            maxLen = max(maxLen, buildPath(start, next, length + 1));
        }
    }
    
    return maxLen;
}

int solve() {
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        result = max(result, buildPath(i, i, 1));
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
