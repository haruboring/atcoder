#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int o_cnt_p = 0, o_cnt_s = 0;

    rep(i, S.size()) {
        if (S[i] == 'a') {
            o_cnt_p++;
        } else {
            break;
        }
    }

    reverse(all(S));
    rep(i, S.size()) {
        if (S[i] == 'a') {
            o_cnt_s++;
        } else {
            break;
        }
    }

    reverse(all(S));

    if (o_cnt_p > o_cnt_s) {
        cout << "No" << endl;
        return 0;
    }

    string Ss = "";
    rep(i, o_cnt_s - o_cnt_p) {
        Ss += "a";
    }
    Ss += S;

    rep(i, Ss.size()) {
        if (Ss[i] != Ss[Ss.size() - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
