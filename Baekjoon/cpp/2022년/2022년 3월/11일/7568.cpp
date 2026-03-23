#include <bits/stdc++.h>
using namespace std;

int n;
int w[50];
int h[50];
int ans[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0 ; i<n ; i++) cin >> w[i] >> h[i];
    for(int i=0 ; i<n ; i++) {
        int cw = w[i];
        int ch = h[i];
        for(int j=0 ; j<n ; j++) if(cw < w[j] && ch < h[j]) ans[i]++;
        ans[i]++;
    }

    for(int i=0 ; i<n ; i++) cout << ans[i] << " ";
}
