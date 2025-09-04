#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, H, W;
    cin >> N >> H >> W;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<int> T;
    rep(i, N) T.push_back(A[i] - 1), T.push_back(B[i] - 1);

    int t = 0;
    rep(i, 2 * N) t ^= T[i];

    if (t == 0) {
        cout << "Second" << endl;
        return 0;
    } else {
        cout << "First" << endl;
        return 0;
    }
}
