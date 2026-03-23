#include <bits/stdc++.h>

using namespace std;

int N, M, sum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        sum[i] = sum[i - 1] + A;
    }

    cin >> M;

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << "\n";
    }
}