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
    vector<int> A(7 * N);
    rep(i, 7 * N) cin >> A[i];

    rep(i, N) {
        int sum = 0;
        rep(j, 7) {
            sum += A[7 * i + j];
        }
        cout << sum << " ";
    }
    cout << endl;
}
