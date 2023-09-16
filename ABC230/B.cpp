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
    int x_cnt = 0;
    bool first_o = true, substring = true;
    rep(i, S.size()) {
        if (S[i] == 'x') {
            x_cnt++;
            if (x_cnt > 2) {
                substring = false;
            }
        } else {
            if (first_o) {
                first_o = false;
                if (x_cnt > 2) {
                    substring = false;
                }
            } else {
                if (x_cnt != 2) {
                    substring = false;
                }
            }
            x_cnt = 0;
        }
    }
    if (substring) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}