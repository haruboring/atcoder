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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int cnt = 0;
    rep(i, N) {
        rep(j, S[i].size() - 1) {
            if (S[i][j] == 'A' && S[i][j + 1] == 'B') cnt++;
        }
    }

    int _a = 0, b_ = 0, b_a = 0;
    rep(i, N) {
        if (S[i][0] == 'B' && S[i][S[i].size() - 1] == 'A') {
            b_a++;
        } else if (S[i][0] == 'B') {
            b_++;
        } else if (S[i][S[i].size() - 1] == 'A') {
            _a++;
        }
    }

    debug(cnt);
    debug(_a);
    debug(b_);
    debug(b_a);

    if (b_a == 0) {
        cout << cnt + min(_a, b_) << endl;
    } else if (_a == 0 && b_ == 0) {
        cout << cnt + b_a - 1 << endl;
    } else if (_a == 0 || b_ == 0) {
        cout << cnt + b_a << endl;
    } else {
        cout << cnt + b_a + 1 + min(_a - 1, b_ - 1) << endl;
    }
}
