#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int Ax, Ay, Bx, By, N;
    cin >> Ax >> Ay >> Bx >> By >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int cnt = 0;

    rep(i, N) {
        ll Cx = X[i], Cy = Y[i], Dx = X[(i + 1) % N], Dy = Y[(i + 1) % N];

        ll s = (Ax - Bx) * (Cy - Ay) + (Ay - By) * (Ax - Cx);
        ll t = (Ax - Bx) * (Dy - Ay) + (Ay - By) * (Ax - Dx);
        ll u = (Cx - Dx) * (Ay - Cy) + (Cy - Dy) * (Cx - Ax);
        ll v = (Cx - Dx) * (By - Cy) + (Cy - Dy) * (Cx - Bx);
        if (s * t <= 0 && u * v <= 0) cnt++;
    }

    cout << cnt / 2 + 1 << endl;
}