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
    int x = -1, y = -1;
    rep(i, 8) {
        if (S[i] == 'B') {
            if (x != -1) {
                y = i + 1;
            } else {
                x = i + 1;
            }
        }
    }
    bool ans = false;
    if (x % 2 == 0 && y % 2 == 1 || x % 2 == 1 && y % 2 == 0) {
        ans = true;
    }
    bool a = false;
    rep(i, 8) {
        if (S[i] == 'R') {
            a = !a;
        }
        if (S[i] == 'K') {
            if (a && ans) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}