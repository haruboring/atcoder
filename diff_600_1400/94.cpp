#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    if (A < B) {
        cout << max(0LL, N - A + 1) << endl;
        return 0;
    }

    ll ans = max(0LL, (N / A - 1) * B);
    if (N / A != 0) ans += max(0LL, min(B, N % A + 1));
    cout << ans << endl;
}