#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<vector<int>> A(9, vector<int>(9));
    rep(i, 9) {
        rep(j, 9) {
            cin >> A[i][j];
        }
    }

    bool ok = true;

    rep(i, 9) {
        set<int> s;
        rep(j, 9) {
            s.insert(A[i][j]);
        }
        if (s.size() != 9) ok = false;
    }

    rep(i, 9) {
        set<int> s;
        rep(j, 9) {
            s.insert(A[j][i]);
        }
        if (s.size() != 9) ok = false;
    }

    rep(i, 3) {
        rep(j, 3) {
            set<int> s;
            repp(k, 3 * i, 3 * i + 3) {
                repp(l, 3 * j, 3 * j + 3) {
                    s.insert(A[k][l]);
                }
            }
            if (s.size() != 9) ok = false;
        }
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}