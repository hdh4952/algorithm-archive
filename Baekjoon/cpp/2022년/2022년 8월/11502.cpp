#include <bits/stdc++.h>
using namespace std;

int t, K;
bool arr[1000];
int ans[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=2 ; i<1000 ; i++) arr[i] = true;
    for(int i=2 ; i<1000 ; i++)
        for(int j=i+i ; j<1000 ; j+=i)
            arr[j] = false;

    for(int i=2 ; i<1000 ; i++) {
        for(int j=2 ; j<1000 ; j++) {
            for(int k=2 ; k<1000 ; k++) {
                if(i + j + k >= 1000) continue;
                if(arr[i] && arr[j] && arr[k] && !ans[i+j+k]) {
                    ans[i+j+k] = ((i * 1000) + j) * 1000 + k;
                }
            }
        }
    }

    cout << arr[12];

    cin >> t;
    while(t--) {
        cin >> K;
        if(!ans[K]) cout << 0 << "\n";
        else cout << ans[K] / 1000000 << " " << ans[K] / 1000 % 1000 << " " << ans[K] % 1000 << "\n";
    }
}