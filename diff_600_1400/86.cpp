#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<double> A(N + 1);
    rep(i, N) cin >> A[i];
    A[N] = 0;
    sort(all(A));

    vector<double> sum(N + 1);
    rep(i, N) sum[i + 1] = sum[i] + A[i + 1];
    double ans = 1e14;
    // N*x + sum[N] - (N-i)*(2x) - sum[i] が最小になるxを求める
    rep(i, N + 1) {
        double x = A[i] / 2;
        ans = min(ans, (N * x + sum[N] - (N - i) * (2 * x) - sum[i]));
    }

    debug(ans);

    cout << fixed << setprecision(20) << (double)ans / N << endl;
}
