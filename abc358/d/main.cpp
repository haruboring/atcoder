#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(all(B));
    reverse(all(B));

    sort(all(A));
    reverse(all(A));

    int ans = 0;
    multiset<int> s;
    int idx = 0;
    rep(i, M) {
        while (idx < N && B[i] <= A[idx]) {
            s.insert(A[idx]);
            idx++;
        }

        if (s.empty()) {
            cout << -1 << endl;
            return 0;
        }

        ans += *s.begin();
        s.erase(s.find(*s.begin()));
    }

    cout << ans << endl;
}
