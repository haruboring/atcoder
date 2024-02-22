#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool ok = false;
    rep(i, N) if (S[i] == 'o') ok = true;
    rep(i, N) if (S[i] == 'x') ok = false;

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
