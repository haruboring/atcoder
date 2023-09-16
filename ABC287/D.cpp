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
    rep(i, T.size() + 1) {
        rep(j, T.size() + 1) {
            if (j == int(T.size())) {
                cout << "Yes" << endl;
                break;
            }
            if (S[(S.size() - T.size() + i + j) % S.size()] != '?' && T[j] != '?') {
                if (S[(S.size() - T.size() + i + j) % S.size()] != T[j]) {
                    cout << "No" << endl;
                    break;
                }
            }
        }
    }
}