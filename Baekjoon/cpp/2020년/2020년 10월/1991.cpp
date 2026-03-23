#include <bits/stdc++.h>

using namespace std;

struct node {
    char data;
    char leftChild;
    char rightChild;
};

struct node arr[27];
int n;

void f1(int x) {
    if (arr[x].data != '.') {
        cout << arr[x].data;
        if(arr[x].leftChild != '.') f1(arr[x].leftChild - 'A');
        if(arr[x].rightChild != '.') f1(arr[x].rightChild - 'A');
    }
}

void f2(int x) {
    if (arr[x].data != '.') {
        if(arr[x].leftChild != '.') f2(arr[x].leftChild - 'A');
        cout << arr[x].data;
        if(arr[x].rightChild != '.') f2(arr[x].rightChild - 'A');
    }
}

void f3(int x) {
    if (arr[x].data != '.') {
        if(arr[x].leftChild != '.') f3(arr[x].leftChild - 'A');
        if(arr[x].rightChild != '.') f3(arr[x].rightChild - 'A');
        cout << arr[x].data;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        char a;
        cin >> a;
        arr[a - 'A'].data = a;
        cin >> arr[a - 'A'].leftChild >> arr[a - 'A'].rightChild;
    }
    f1(0);
    cout << "\n";
    f2(0);
    cout << "\n";
    f3(0);
}