#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N), Z(N);
    rep(i, N) cin >> X.at(i) >> Y.at(i) >> Z.at(i);

    ll sum = 0;
    rep(i, N) sum += Z[i];
    ll T = (sum + 1) / 2;

    rep(i, N) {
        if (X[i] > Y[i]) T -= Z[i];
    }
    if (T < 0) {
        T = 0;
    }

    vector<pair<ll, ll>> cost_get(0);
    rep(i, N) {
        if (X[i] > Y[i]) continue;
        cost_get.push_back(make_pair((Y[i] - X[i] + 1) / 2, Z[i]));
    }

    N = cost_get.size();

    vector<ll> dp(T + 1, 1e18);
    dp[0] = 0;
    rep(i, N) {
        for (int j = T; j >= 0; j--) {
            dp[min(T, j + cost_get[i].second)] = min(dp[min(T, j + cost_get[i].second)], dp[j] + cost_get[i].first);
        }
    }

    cout << dp[T] << endl;
}