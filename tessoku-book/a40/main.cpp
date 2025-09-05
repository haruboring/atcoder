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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, int> m;
    rep(i, N) m[A[i]]++;

    int ans = 0;
    for (auto [k, c] : m) {
        int t = 1;
        rep(i, 3) t *= c - i;
        ans += t / 6;
    }

    cout << ans << endl;
}
