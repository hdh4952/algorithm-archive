#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

vector<int> v;

void init(int size, string s) {
    if(size == 8) return;
    v.push_back(stoi(s));
    init(size + 1, s + "4");
    init(size + 1, s + "7");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    init(0, "4");
    init(0, "7");
    sort(v.begin(), v.end());
    int pre = 0;
    for(auto i : v) {
        if(N < i) {
            cout << pre;
            return 0;
        } else pre = i;
    }
}