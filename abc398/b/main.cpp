#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> A(7);
    rep(i, 7) cin >> A[i];

    sort(all(A));
    map<int, int> m;
    rep(i, 7) m[A[i]]++;

    vector<int> K(0);
    for (auto [k, v] : m) {
        K.push_back(v);
    }

    if (K.size() == 1) {
        cout << "No" << endl;
        return 0;
    }

    sort(all(K));
    reverse(all(K));

    if (K[0] >= 3 && K[1] >= 2) {
        cout << "Yes" << endl;

    } else {
        cout << "No" << endl;
    }
}
