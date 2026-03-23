#include <bits/stdc++.h>

using namespace std;

void f();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) f();
}

void f() {
    int n, m;
    int arr[1000000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int start = 0;
        int end = n - 1;
        bool flag = false;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (x == arr[mid]) {
                flag = true;
                break;
            }
            if (x < arr[mid]) end = mid - 1;
            if (x > arr[mid]) start = mid + 1;
        }
        if (flag) cout << "1" << "\n";
        else cout << "0" << "\n";
    }
}