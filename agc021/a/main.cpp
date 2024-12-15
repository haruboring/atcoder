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

    vector<int> v;
    int n = 9;
    rep(i, 17) {
        v.push_back(n);
        n = n * 10 + 9;
    }
    sort(all(v));

    int idx = lower_bound(all(v), N) - v.begin();
    if (idx == 0) {
        cout << N << endl;
        return 0;
    }

    debug(idx);

    int ans = 0;
    rep(i, 17) {
        ans += v[idx - 1] % 10;
        v[idx - 1] /= 10;
    }
    string sn = to_string(N);

    cout << ans + sn[0] - '0' - 1 << endl;
}
