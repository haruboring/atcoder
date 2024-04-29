#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    vector<bool> lb(T.size() + 1, false), rb(T.size() + 1, false);
    lb[0] = true;
    rep(i, T.size()) {
        if (S[i] == '?' || T[i] == '?') {
            lb[i + 1] = true;
        } else if (S[i] == T[i]) {
            lb[i + 1] = true;
        } else {
            break;
        }
    }
    reverse(all(S)), reverse(all(T));
    rb[0] = true;
    rep(i, T.size()) {
        if (S[i] == '?' || T[i] == '?') {
            rb[i + 1] = true;
        } else if (S[i] == T[i]) {
            rb[i + 1] = true;
        } else {
            break;
        }
    }

    rep(i, T.size() + 1) {
        if (lb[i] && rb[T.size() - i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
