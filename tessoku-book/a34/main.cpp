#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int mex(int a, int b = 1e18) {
    for (int i = 0; i < 3; i++) {
        if (i != a && i != b) return i;
    }
}

signed main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> T(1e7);
    for (int i = X; i <= 1e7; i++) {
        int g = mex(T[i - X]);
        if (i - Y >= 0) {
            g = mex(T[i - Y], T[i - X]);
        }

        T[i] = g;
    }

    int t = 0;
    rep(i, N) t ^= T[A[i]];
    if (t == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}
