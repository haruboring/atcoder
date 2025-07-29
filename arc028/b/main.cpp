#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    if (K == 1) {
        int mi = 1e18, ex;
        rep(i, N) {
            if (X[i] < mi) {
                mi = X[i];
                ex = i;
            }
            cout << ex + 1 << endl;
        }
        return 0;
    }

    set<pair<int, int>> s;
    rep(i, K) s.insert({X[i], i});
    auto sr = *s.rbegin();
    cout << sr.second + 1 << endl;

    repp(i, K, N) {
        auto sr = *s.rbegin();
        if (X[i] < sr.first) {
            s.erase(sr);
            s.insert({X[i], i});
        }

        sr = *s.rbegin();
        cout << sr.second + 1 << endl;
    }
}
