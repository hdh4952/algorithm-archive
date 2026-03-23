#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, arr[100], a, b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << "A";
        return 0;
    } else if (n == 2) {
        if (arr[0] == arr[1]) cout << arr[1];
        else cout << "A";
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (i == 2) {
            if (arr[1] == arr[0] && arr[2] != arr[1]) {
                cout << "B";
                return 0;
            }
            if (arr[2] - arr[1] == 0) a = 0;
            else if ((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0) {
                cout << "B";
                return 0;
            }
            else a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
            b = arr[1] - arr[0] * a;
        }
        if (arr[i] != arr[i - 1] * a + b) {
            cout << "B";
            return 0;
        }
    }
    cout << arr[n - 1] * a + b;
}