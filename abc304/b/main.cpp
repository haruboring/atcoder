#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string N;
    cin >> N;

    if (N.size() < 4) {
        cout << N << endl;
        return 0;
    }

    rep(i, 3) cout << N[i];
    repp(i, 3, N.size()) cout << 0;
    cout << endl;
}
