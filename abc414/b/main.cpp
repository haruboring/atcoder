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
    vector<char> c(N);
    vector<int> l(N);
    rep(i, N) cin >> c[i] >> l[i];

    int len = 0;
    rep(i, N) {
        len += l[i];
        if (len > 100) break;
    }
    if (len > 100) {
        cout << "Too Long" << endl;
        return 0;
    }

    rep(i, N) {
        rep(j, l[i]) {
            cout << c[i];
        }
    }

    cout << endl;
}
