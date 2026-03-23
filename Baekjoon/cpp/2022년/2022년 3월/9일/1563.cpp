#include <bits/stdc++.h>
using namespace std;

int n;
int dp[3][1001];
int dp2[2][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    dp[0][2] = dp[1][2] = 3;
    dp[2][2] = 2;
    dp2[0][1] = dp2[1][1] = 1;
    dp2[0][2] = dp2[1][2] = 2;

    for(int i=3 ; i<=n ; i++) {
        dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1])%1000000;
        dp[1][i] = (dp[0][i-1] + dp[0][i-2] + dp[2][i-1] + dp[2][i-2])%1000000;
        dp2[0][i] = (dp2[0][i-1] + dp2[1][i-1])%1000000;
        dp2[1][i] = (dp2[0][i-1] + dp2[0][i-2])%1000000;
        dp[2][i] = (dp2[0][i-1] + dp2[1][i-1])%1000000;
    }

    cout << (dp[0][n] + dp[1][n] + dp[2][n])%1000000;
}
