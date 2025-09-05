#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    map<int, vector<int>> m;
    rep(i, N) m[X[i]].push_back(Y[i]);

    multiset<int> s;
    int ans = 0;
    rep(i, D + 1) {
        for (auto a : m[i]) s.insert(a);
        if (!s.empty()) {
            int t = *s.rbegin();
            ans += t;
            s.erase(s.find(t));
        }
    }

    cout << ans << endl;
}
