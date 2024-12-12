// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T, g;
    cin >> N >> T >> g;
    vector<int> w(N), h(N);
    rep(i, N) cin >> w[i] >> h[i];

    rep(_, T) {
        cout << N << endl;
        rep(i, N) {
            int p = i;
            int r = 0;
            if (w[i] < h[i]) r = 1;
            char d = 'L';
            int b = -1;

            cout << p << " " << r << " " << d << " " << b << endl;
        }
    }
}

/*
n
p0, r0, d0, b0
*/