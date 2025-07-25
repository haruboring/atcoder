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

    sort(all(A));

    int r = 0;
    rep(i, N - 1) r += A[i + 1] - A[0];
    int sum = r;
    repp(i, 1, N) {
        r -= (N - i) * (A[i] - A[i - 1]);
        sum += r;
    }

    cout << sum << endl;
}
