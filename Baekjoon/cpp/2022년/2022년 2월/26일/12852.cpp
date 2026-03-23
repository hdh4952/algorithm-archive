#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0 && i % 3 == 0) dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3])) + 1;
        else if (i % 3 == 0) dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        else if (i % 2 == 0) dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        else dp[i] = dp[i - 1] + 1;
    }

    cout << dp[n] << "\n" << n << " ";

    int s = n;
    while (s != 1) {
        if (s % 3 == 0 && dp[s / 3] + 1 == dp[s]) {
            s /= 3;
            cout << s << " ";
        } else if (s % 2 == 0 && dp[s / 2] + 1 == dp[s]) {
            s /= 2;
            cout << s << " ";
        } else {
            s--;
            cout << s << " ";
        }
    }
}