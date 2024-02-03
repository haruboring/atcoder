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

    int mini = 1e9;

    int wa = A[0];
    mini = wa;
    repp(i, 1, N) {
        wa += A[i];
        mini = min(mini, wa);
    }

    if (mini >= 0) {
        cout << wa << endl;
    } else {
        cout << abs(mini) + wa << endl;
    }
}
