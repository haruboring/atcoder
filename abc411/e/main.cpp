#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(6));
    rep(i, N) rep(j, 6) {
        int x;
        cin >> x;
        A[i][j] = x;
    }

    unordered_map<int, mint> s, ns;
    s[0] = (mint)1;
    rep(i, N) {
        ns.clear();
        rep(j, 6) {
            int x = A[i][j];
            for (auto [v, p] : s) {
                ns[max(v, x)] += p / (mint)6;
            }
        }
        s = ns;
    }
    mint ans = 0;
    for (auto [v, p] : s) ans += (mint)v * p;
    cout << ans.val() << endl;
}