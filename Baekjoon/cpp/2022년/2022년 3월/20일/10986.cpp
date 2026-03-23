#include <bits/stdc++.h>
using namespace std;

int n, m;
long long int ans;
long long int arr[1000001];
long long int cnt[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1 ; i<=n ; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        arr[i] %= m;
        cnt[arr[i]]++;
    }

    for(int i=0 ; i<m ; i++)
        ans += cnt[i] * (cnt[i]-1) / 2;

    cout << ans + cnt[0];
}