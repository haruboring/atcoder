#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    bool one = false;
    int m = -1;
    rep(i, N) {
        cin >> C[i];
        if (C[i] == T) {
            one = true;
        }
    }
    if (one == false) {
        T = C[0];
    }
    rep(i, N) {
        cin >> R[i];
        if (C[i] == T) {
            m = max(m, R[i]);
        }
    }

    rep(i, N) {
        if (C[i] == T && R[i] == m) {
            cout << i + 1 << endl;
        }
    }
}