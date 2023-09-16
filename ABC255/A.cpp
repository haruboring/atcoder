#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int R, C;
    cin >> R >> C;
    rep(i, 2) {
        rep(j, 2) {
            int A;
            cin >> A;
            if (i == R - 1 && j == C - 1) {
                cout << A << endl;
            }
        }
    }
}