#include <bits/stdc++.h>
using namespace std;

int n, ans;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        ans += a+b;
    }

    cout << ans;
}
