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
    string S;
    cin >> N >> S;

    vector<int> a, b;
    rep(i, 2 * N) {
        if (S[i] == 'A') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    // ABAB
    int cn = 0;
    rep(i, N) cn += abs(a[i] - 2 * i);

    // BABA
    int cnn = 0;
    rep(i, N) cnn += abs(b[i] - 2 * i);

    cout << min(cn, cnn) << endl;
}
