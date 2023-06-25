#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(7 * N);
    rep(i, 7 * N) cin >> A[i];

    rep(i, N) {
        ll sum = 0;
        rep(j, 7) {
            sum += A[i * 7 + j];
        }
        cout << sum << " ";
    }
    cout << endl;
}