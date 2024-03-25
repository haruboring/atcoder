#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int W, B;
    cin >> W >> B;

    string S = "wbwbwwbwbwbw";
    string Ss = "";
    rep(_, 100) {
        Ss += S;
    }

    int N = Ss.size();
    set<pair<int, int>> s;
    int w_cnt = 0, b_cnt = 0;
    rep(i, N) {
        s.insert({w_cnt, b_cnt});
        if (Ss[i] == 'w') {
            w_cnt++;
        } else {
            b_cnt++;
        }
    }

    w_cnt = 0, b_cnt = 0;
    rep(i, N) {
        if (s.count({w_cnt + W, b_cnt + B})) {
            cout << "Yes" << endl;
            return 0;
        }
        if (Ss[i] == 'w') {
            w_cnt++;
        } else {
            b_cnt++;
        }
    }

    cout << "No" << endl;
}
