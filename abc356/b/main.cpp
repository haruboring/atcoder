#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    vector<int> ses(M);
    rep(i, N) {
        rep(j, M) {
            int x;
            cin >> x;
            ses[j] += x;
        }
    }

    rep(i, M) {
        if (ses[i] < A[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
