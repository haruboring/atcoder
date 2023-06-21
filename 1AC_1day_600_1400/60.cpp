#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    rep(i, M) cin >> X[i];

    sort(all(X));
    vector<int> dis(M - 1);
    rep(i, M - 1) {
        dis[i] = X[i + 1] - X[i];
    }
    sort(all(dis));

    int ans = 0;
    rep(i, M - N) {
        ans += dis[i];
    }

    cout << ans << endl;
}
