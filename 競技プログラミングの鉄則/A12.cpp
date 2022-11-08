#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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