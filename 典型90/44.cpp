#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> T(Q), X(Q), Y(Q);
    rep(i, Q) cin >> T[i] >> X[i] >> Y[i];

    int shift = 0;
    rep(i, Q) {
        int t = T[i];
        int x = X[i];
        int y = Y[i];

        x--, y--;

        if (t == 1) {
            swap(A[(x - shift + N) % N], A[(y - shift + N) % N]);
        } else if (t == 2) {
            shift++;
            shift %= N;
        } else {
            cout << A[(x - shift + N) % N] << endl;
        }
    }
}