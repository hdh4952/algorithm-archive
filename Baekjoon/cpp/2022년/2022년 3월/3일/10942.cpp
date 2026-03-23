#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[2001];
bool isP[2001][2001];

bool f(int s, int e) {
    if(s == e) return true;
    if(isP[s][e]) return isP[s][e];
    if(s+1 == e) {
        if(arr[s] == arr[e]) return isP[s][e] = true;
        else return false;
    }
    if(f(s+1, e-1) && arr[s] == arr[e]) return isP[s][e] = true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> arr[i];
    cin >> m;
    int s, e;
    while(m--) {
        cin >> s >> e;
        cout << f(s, e) << "\n";
    }
}
