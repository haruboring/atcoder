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
    vector<int> A(N), C(N);
    rep(i, N) {
        cin >> A[i] >> C[i];
    }

    map<int, int> mp;
    rep(i, N) {
        if (mp.find(C[i]) == mp.end()) {
            mp[C[i]] = A[i];
        } else {
            int mi = min(mp[C[i]], A[i]);
            mp[C[i]] = mi;
        }
    }

    int ans = 0;
    for (auto [c, a] : mp) {
        ans = max(ans, a);
    }

    cout << ans << endl;
}
