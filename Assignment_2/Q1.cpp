#include <bits/stdc++.h>
using namespace std;

//Memoization

// int solve(int n, vector<int>& dp) {
//     if (n == 1) return 0;

//     if (dp[n] != -1) return dp[n];   


//     int x = INT_MAX;


//     if (n % 2 == 0) {
     
//         x = 1 + solve(n / 2, dp);
//     } else {
    
//         x = 1 + min(
//             solve(n - 1, dp),
//             solve(n + 1, dp)
//         );
//     }
//     return dp[n] = x;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {


    //Tabulation


    int n;
    cin >> n;

    vector<int> dp(n + 2, 0); 


    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            dp[i] = 1 + dp[i / 2];
        } else {
            dp[i] = 1 + min(dp[i - 1], dp[i + 1]);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}

