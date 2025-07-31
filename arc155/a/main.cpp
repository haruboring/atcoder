#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    debug(400378271514996652 % 12);
    int T;
    cin >> T;

    rep(_, T) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;

        // K <= Nだと、直接見たらいいだけ
        K = K % (2 * N);
        string S_ = "";
        rep(i, K) S_ += "-";
        rep(i, min(N, K)) S_[i] = S[N - 1 - i];
        rep(i, min(N, K)) S_[K - 1 - i] = S[i];
        bool ok = true;
        string ss_ = S + S_;
        rep(i, ss_.size()) if (ss_[i] != ss_[ss_.size() - 1 - i]) ok = false;
        string s_s = S_ + S;
        rep(i, s_s.size()) if (s_s[i] != s_s[s_s.size() - 1 - i]) ok = false;

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
