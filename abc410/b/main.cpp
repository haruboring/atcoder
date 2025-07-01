#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    set<pair<int, int>> s;
    map<int, int> m;
    rep(i, N) s.insert({0, i + 1});
    rep(i, Q) {
        if (X[i] == 0) {
            auto [c, idx] = *s.begin();
            s.erase({c, idx});
            s.insert({c + 1, idx});
            m[idx] = c + 1;

            cout << idx << " ";
        } else {
            int idx = X[i], c = m[idx];
            s.erase({c, idx});
            s.insert({c + 1, idx});
            m[idx]++;

            cout << idx << " ";
        }
    }
    cout << endl;
}
