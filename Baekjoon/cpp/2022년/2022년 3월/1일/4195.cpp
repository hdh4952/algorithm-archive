#include <bits/stdc++.h>
using namespace std;

void f();
void merge(int a, int b);
int find(int a);
int UF[200001];
int cnt[200001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--) f();
}

void f() {
    int f, n = 1;
    map<string, int> m;

    cin >> f;
    for(int i=1 ; i<=2*f ; i++) {
        UF[i] = i;
        cnt[i] = 1;
    }

    while(f--) {
        string name1, name2;
        cin >> name1 >> name2;
        if(m.find(name1) == m.end()) m[name1] = n++;
        if(m.find(name2) == m.end()) m[name2] = n++;
        merge(m[name1], m[name2]);
        cout << cnt[find(m[name1])] << "\n";
    }
}

int find(int a) {
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x != y) cnt[x] += cnt[y];
    UF[y] = x;
}