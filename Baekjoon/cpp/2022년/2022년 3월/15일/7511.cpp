#include <bits/stdc++.h>
using namespace std;

void f();
void merge(int a, int b);
int find(int a);
int UF[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++) {
        cout << "Scenario " << i << ":\n";
        f();
        cout << "\n";
    }
}

void f() {
    int n, k, m;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++) UF[i] = i;
    while(k--) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    cin >> m;
    for(int i=0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)) cout << "1\n";
        else cout << "0\n";
    }
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    UF[y] = x;
}

int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}