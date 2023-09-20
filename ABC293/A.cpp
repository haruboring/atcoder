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

    rep(i, S.size() / 2) {
        char a = S[2 * i];
        S[2 * i] = S[2 * i + 1];
        S[2 * i + 1] = a;
    }

    cout << S << endl;
}