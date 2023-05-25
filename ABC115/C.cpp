#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    sort(all(h));
    int ans = 1e9;
    rep(i, N - K + 1) {
        ans = min(ans, h[i + K - 1] - h[i]);
    }

    cout << ans << endl;
}