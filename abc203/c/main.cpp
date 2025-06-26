#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    map<int, int> m;
    rep(i, N) m[A[i]] += B[i];

    vector<int> Aa(0), Bb(0);
    for (auto [k, c] : m) {
        Aa.push_back(k);
        Bb.push_back(c);
    }

    if (K < Aa[0]) {
        cout << K << endl;
        return 0;
    }
    K = K - Aa[0] + Bb[0];
    repp(i, 1, Aa.size()) {
        if (K < (Aa[i] - Aa[i - 1])) {
            cout << Aa[i - 1] + K << endl;
            return 0;
        }
        K = K - (Aa[i] - Aa[i - 1]) + Bb[i];
    }

    debug(K);

    cout << Aa[Aa.size() - 1] + K << endl;
}
