#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    ll lef = 0, rig = 1000000000, mid;
    while (lef != rig) {
        mid = (lef + rig) / 2;
        ll sum = 0;
        rep(i, N) {
            sum += mid / A[i];
        }
        if ((sum - K) >= 0) {
            rig = mid;
        } else {
            lef = mid + 1;
        }
    }
    cout << lef << endl;
}