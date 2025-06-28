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
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    int cnt = 0;
    map<int, int> m;
    rep(i, K) {
        if (m[C[i]] == 0) cnt++;
        m[C[i]]++;
    }

    int ans = cnt;
    repp(i, K, N) {
        // cout << "in" << i << " out" << i - K << endl;
        if (m[C[i - K]] == 1) cnt--;
        m[C[i - K]]--;
        if (m[C[i]] == 0) cnt++;
        m[C[i]]++;

        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
