#include <bits/stdc++.h>
using namespace std;

int n, N;
vector<int> tmp;

void f(int cnt) {
    if(cnt == n) {
        cout << tmp.back() << "\n";
    }

    for(int i=0 ; i<=9 ; i++) {
        if(tmp.empty()) {
            if(i == 0) continue;
            if(i == 2 || i == 3 || i == 5 || i == 7) {
                tmp.push_back(i);
                f(cnt+1);
                tmp.pop_back();
            }
        }else {
            bool flag = false;
            int x = tmp.back()*10 + i;
            for(int i=2 ; i<x ; i++) {
                if(x % i == 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                tmp.push_back(x);
                f(cnt+1);
                tmp.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    f(0);
}