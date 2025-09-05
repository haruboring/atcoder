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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    map<int, vector<int>> m;
    rep(i, N) m[A[i]].push_back(B[i]);
    int cnt = 0;
    for (int i = 0; i < 101; i++) {
        vector<int> T;
        rep(j, K + 1) for (auto a : m[i + j]) T.push_back(a);

        if (T.size() == 0) continue;
        sort(all(T));
        rep(j, T.size()) {
            int idx = upper_bound(all(T), T[j] + K) - T.begin() - j;
            cnt = max(cnt, idx);
        }
    }

    cout << cnt << endl;
}
