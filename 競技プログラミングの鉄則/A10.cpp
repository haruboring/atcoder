#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int D;
    cin >> D;
    vector<int> L(D), R(D);
    rep(i, D) {
        cin >> L[i] >> R[i];
    }
    vector<int> lmax(N + 1);
    rep(i, N) {
        lmax[i + 1] = max(lmax[i], A[i]);
    }
    vector<int> rmax(N + 1);
    rep(i, N) {
        rmax[N - 1 - i] = max(rmax[N - i], A[N - 1 - i]);
    }
    rep(i, D) {
        cout << max(lmax[L[i]-1], rmax[R[i]]) << endl;
    }
}