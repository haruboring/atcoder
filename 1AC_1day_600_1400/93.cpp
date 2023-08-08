#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> X(Q);
    rep(i, Q) cin >> X[i];

    sort(all(A));
    vector<ll> cost_to_zero(N + 1), cost_to_inf(N + 1);
    rep(i, N) cost_to_zero[i + 1] = cost_to_zero[i] + A[i];
    rep(i, N) cost_to_inf[N - i - 1] = cost_to_inf[N - i] + (1e9 - A[N - i - 1]);

    rep(i, Q) {
        ll x = X[i];
        ll ans = 0;
        int idx = lower_bound(all(A), x) - A.begin();
        ans += cost_to_inf[idx] - x * idx;
        ans += cost_to_zero[idx] - (1e9 - x) * (N - idx);

        cout << -ans << endl;
    }
}