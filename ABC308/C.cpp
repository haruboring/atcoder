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
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<pair<long double, int>> C(N);
    rep(i, N) {
        C[i].first = (long double)A[i] / (A[i] + B[i]);
        C[i].second = -i;
    }

    sort(all(C));
    reverse(all(C));

    rep(i, N) {
        cout << -C[i].second + 1 << " ";
    }
    cout << endl;
}