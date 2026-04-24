#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;

  bool operator<(const Point& o) const {
    if (x != o.x) return x < o.x;
    return y < o.y;
  }
  friend istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

// Vector(p1 -> p2) to p3
int ccw(Point p1, Point p2, Point p3) {
  p1.x -= p2.x;
  p1.y -= p2.y;
  p3.x -= p2.x;
  p3.y -= p2.y;

  long long t = p1.x * p3.y - p3.x * p1.y;
  if (t > 0)
    return 1;
  else if (t < 0)
    return -1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  Point p1, p2, p3, p4;
  cin >> p1 >> p2 >> p3 >> p4;
  if (p2 < p1) swap(p1, p2);
  if (p4 < p3) swap(p3, p4);

  int c1 = ccw(p1, p2, p3) * ccw(p1, p2, p4),
      c2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  auto compare = [](const Point& p1, const Point& p2) {
    if (p1.x != p2.x) return p2.x - p1.x;
    return p2.y - p1.y;
  };

  if (c1 + c2 < 0)
    cout << 1;
  else if (c1 == 0 && c2 == 0 && (compare(p2, p3) <= 0 && compare(p4, p1) <= 0))
    cout << 1;
  else
    cout << 0;
}