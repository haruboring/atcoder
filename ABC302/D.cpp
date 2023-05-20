#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(all(A));
    sort(all(B));

    ll sum = -1;

    rep(i, N) {
        int ind = lower_bound(all(B), A[i] + D) - B.begin();
        if (B[ind] != A[i] + D) {
            ind--;
        }

        if (abs(A[i] - B[ind]) <= D) {
            sum = max(sum, abs(A[i] + B[ind]));
        }
    }

    cout << sum << endl;
}