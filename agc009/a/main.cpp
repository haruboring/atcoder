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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if ((A[i] + cnt) % B[i] == 0) continue;
        cnt += B[i] - (A[i] + cnt) % B[i];
    }

    cout << cnt << endl;
}
