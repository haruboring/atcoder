#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

bool is_cross(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
    double s, t;
    s = (ax - bx) * (cy - ay) - (ay - by) * (cx - ax);
    t = (ax - bx) * (dy - ay) - (ay - by) * (dx - ax);
    if (s * t > 0) return false;

    s = (cx - dx) * (ay - cy) - (cy - dy) * (ax - cx);
    t = (cx - dx) * (by - cy) - (cy - dy) * (bx - cx);
    if (s * t > 0) return false;

    return true;
}

signed main() {
    double Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    int N;
    cin >> N;
    vector<double> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int cnt = 0;
    int pm = -1;
    rep(i, N) if (is_cross(Ax, Ay, Bx, By, X[i], Y[i], X[(i + 1) % N], Y[(i + 1) % N])) cnt++;

    debug(cnt);
    cout << cnt / 2 + 1 << endl;
}
