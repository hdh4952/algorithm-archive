#include <bits/stdc++.h>
#define REP(i, a, b) for(int i=a ; i<=b ; i++)
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, ans;
    cin >> a >> b;
    ans = abs((a / 4 + bool(a % 4)) - (b / 4 + bool(b % 4)));
    if(!(a % 4)) a = 4;
    else a %= 4;
    if(!(b % 4)) b = 4;
    else b %= 4;
    cout << ans + abs(a - b);
}