#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(M, vector<int>(N));
    vector<vector<int>> dp(M, vector<int>(N, 0));
    for(auto &i : v)
        for(auto &j : i)
            cin >> j;

    for(int i=0 ; i<M ; i++)
        dp[i][0] = v[i][0];

    for(int i=1 ; i<N ; i++) {
        for(int j=0 ; j<M ; j++) {
            int temp = 0;
            for(int k=0 ; k<M ; k++) {
                if(k == j) continue;
                temp = max(temp, dp[k][i-1]);
            }
            dp[j][i] = max(v[j][i] / 2 + dp[j][i-1], v[j][i] + temp);
        }
    }

    int answer = 0;
    for(auto i : dp)
        answer = max(answer, i.back());
    cout << answer;
}