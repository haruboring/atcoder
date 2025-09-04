#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> T = {0, 0, 1, 1, 2};

    int t = 0;
    rep(i, N) t ^= T[A[i] % 5];
    if (t == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}
