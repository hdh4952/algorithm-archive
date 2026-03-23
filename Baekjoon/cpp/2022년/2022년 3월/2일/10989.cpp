#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    while(n--) {
        cin >> x;
        arr[x]++;
    }
    for(int i=1 ; i<=10000 ; i++)
        for(int j=0 ; j<arr[i] ; j++)
            cout << i << "\n";
}