#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    int rest = N;
    int time = 0;
    rep(i, M) {
        rest -= A[i] - time;
        if (rest <= 0) {
            cout << "No" << endl;
            return 0;
        }
        rest += B[i] - A[i];
        rest = min(rest, N);
        time = B[i];
    }

    rest -= T - time;
    if (rest <= 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
