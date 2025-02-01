#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, R;
    cin >> N >> R;
    vector<int> D(N), A(N);
    rep(i, N) cin >> D[i] >> A[i];

    rep(i, N) {
        if (D[i] == 1 && (1600 <= R && R < 2800)) R += A[i];
        if (D[i] == 2 && (1200 <= R && R < 2400)) R += A[i];
    }

    cout << R << endl;
}
