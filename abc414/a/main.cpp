#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int cnt = 0;
    rep(i, N) {
        if (X[i] <= L && R <= Y[i]) cnt++;
    }
    cout << cnt << endl;
}
