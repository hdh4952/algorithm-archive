#include <bits/stdc++.h>

using namespace std;

int n, A[1001], tmp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && tmp[j] >= tmp[i]) {
                tmp[i] = tmp[j] + 1;
            }
        }
    }
    /*
    for(int i=0 ; i<=n ; i++) {
        cout << tmp[i] << " ";
    }
    */
    sort(tmp, tmp + n + 1);
    cout << tmp[n];
}