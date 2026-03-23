#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr[i] = a + arr[i - 1];
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << "\n";
    }
}