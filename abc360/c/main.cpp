#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N), W(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> W[i];

    map<int, vector<int>> m;
    rep(i, N) m[A[i]].push_back(W[i]);

    int ans = 0;
    for (auto [k, v] : m) {
        if (v.size() == 1) continue;
        sort(all(v));
        rep(i, v.size() - 1) ans += v[i];
    }

    cout << ans << endl;
}
