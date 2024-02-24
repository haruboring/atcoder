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
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    int Q;
    cin >> Q;
    vector<int> A(Q), B(Q);
    rep(i, Q) cin >> A[i] >> B[i];

    map<int, int> mp;
    rep(i, N) mp[P[i]] = i + 1;

    rep(i, Q) {
        if (mp[A[i]] < mp[B[i]]) {
            cout << A[i] << endl;
        } else {
            cout << B[i] << endl;
        }
    }
}
