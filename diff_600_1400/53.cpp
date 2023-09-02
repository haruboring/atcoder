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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 1e9;
    repp(i, -100, 100 + 1) {
        int tmp = 0;
        rep(j, N) {
            tmp += (A[j] - i) * (A[j] - i);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}