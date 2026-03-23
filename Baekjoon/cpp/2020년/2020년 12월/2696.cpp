#include <iostream>

using namespace std;

void f() {
    int m, arr[10000] = {0,}, cnt = 0, res[10000] = {0,};

    cin >> m;

    for (int i = 1; i <= m; i++) {
        int tmp, cmp = i - 2;
        cin >> tmp;
        while (cmp >= 0 && arr[cmp] > tmp) {
            arr[cmp + 1] = arr[cmp];
            cmp--;
        }
        arr[cmp + 1] = tmp;
        if (i % 2 != 0) {
            res[cnt] = arr[i / 2];
            cnt++;
        }
    }

    cout << cnt << "\n";
    for (int i = 1; i < cnt + 1; i++) {
        cout << res[i - 1] << " ";
        if (i % 10 == 0) cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--) f();
}