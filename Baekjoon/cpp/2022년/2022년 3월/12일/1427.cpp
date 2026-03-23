#include <bits/stdc++.h>
using namespace std;

int arr[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    for(int i=0 ; i<str.size() ; i++) arr[i] = str[i]-'0';
    sort(arr, arr+str.size(), greater());
    for(int i=0 ; i<str.size() ; i++) cout << arr[i];
}
