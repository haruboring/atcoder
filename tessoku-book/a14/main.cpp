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
    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    rep(i, N) cin >> D[i];

    set<int> s;
    rep(i, N) rep(j, N) s.insert(C[i] + D[j]);

    rep(i, N) rep(j, N) if (s.count(K - A[i] - B[j])) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
