// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(Q);
    rep(i, Q) cin >> A[i];

    vector<int> scores(N, K - Q);
    rep(i, Q) scores[A[i] - 1]++;

    rep(i, N) {
        if (scores[i] > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}