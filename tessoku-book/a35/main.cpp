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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> T = A;
    for (int i = N; i > 1; i--) {
        rep(j, i - 1) {
            if (i % 2) {
                T[j] = min(T[j], T[j + 1]);
            } else {
                T[j] = max(T[j], T[j + 1]);
            }
        }
    }

    cout << T[0] << endl;
}
