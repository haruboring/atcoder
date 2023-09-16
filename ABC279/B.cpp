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
    int Ss = S.size();
    int Ts = T.size();
    if (Ss < Ts) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, Ss - Ts + 1) {
        bool b = true;
        rep(j, Ts) {
            if (T[j] != S[i + j]) {
                b = false;
            }
        }
        if (b) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}