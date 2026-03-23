#include <bits/stdc++.h>

using namespace std;

int a, b, c;
long long int m[51][51][51];

long long int solve(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) return 1;
    if (m[x][y][z]) return m[x][y][z];
    if (x > 20 || y > 20 || z > 20) return m[x][y][z] = solve(20, 20, 20);
    if (x < y && y < z) return m[x][y][z] = solve(x, y, z - 1) + solve(x, y - 1, z - 1) - solve(x, y - 1, z);
    return m[x][y][z] = solve(x - 1, y, z) + solve(x - 1, y - 1, z) + solve(x - 1, y, z - 1) - solve(x - 1, y - 1, z - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (a + 1 || b + 1 || c + 1) {
        cin >> a >> b >> c;
        if(!(a+1 || b+1 || c+1)) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
    }

}
