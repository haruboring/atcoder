#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, P - 1) {
        cout << A[i] << " ";
    }
    rep(i, Q - P + 1) {
        cout << A[R - 1 + i] << " ";
    }
    rep(i, R - Q - 1) {
        cout << A[Q + i] << " ";
    }
    rep(i, Q - P + 1) {
        cout << A[P - 1 + i] << " ";
    }
    rep(i, N - S) {
        cout << A[S + i] << " ";
    }

    cout << endl;
}