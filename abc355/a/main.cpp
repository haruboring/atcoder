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

    if (A == B) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, 3) {
        if (A == i + 1) continue;
        if (B == i + 1) continue;
        cout << i + 1 << endl;
    }
}
