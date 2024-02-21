#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    bool ok = true;
    if (S[A] != '-') ok = false;
    rep(i, A + B + 1) {
        if (i == A) continue;
        if (!('0' <= S[i] && S[i] <= '9')) ok = false;
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
