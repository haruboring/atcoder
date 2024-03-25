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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = (1 + K) * K / 2;

    set<int> s;
    rep(i, N) {
        if (A[i] <= K) s.insert(A[i]);
    }

    for (auto a : s) {
        ans -= a;
    }

    cout << ans << endl;
}
