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
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    multiset<int> s;
    rep(i, N) s.insert(i + 1);
    rep(i, N) s.insert(i + 1);
    rep(i, K) s.erase(s.find(A[i]));

    vector<int> R;
    for (auto x : s) R.push_back(x);
    sort(all(R));

    if ((2 * N - K) % 2 == 0) {
        int ans = 0;
        rep(i, R.size() / 2) {
            ans += R[i * 2 + 1] - R[i * 2];
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> even(2 * N - K), odd(2 * N - K);
    repp(i, 1, 2 * N - K) {
        if (i % 2 == 0) {
            even[i] = even[i - 1] + R[i] - R[i - 1];
            odd[i] = odd[i - 1];
        } else {
            even[i] = even[i - 1];
            odd[i] = odd[i - 1] + R[i] - R[i - 1];
        }
    }

    int ans = 1e18;
    rep(i, 2 * N - K - 1) {
        ans = min(ans, odd[i] + even[2 * N - K - 1] - even[i + 1]);
    }
    cout << ans << endl;
}
