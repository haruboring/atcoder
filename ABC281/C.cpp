#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    T %= sum;
    ll ans = 0;
    rep(i, N) {
        if (ans + A[i] >= T) {
            cout << i + 1 << " " << T - ans << endl;
            return 0;
        }
        ans += A[i];
    }
}