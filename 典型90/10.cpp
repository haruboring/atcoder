#include "atcoder/all"
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
    vector<int> S1(N), S2(N);
    rep(i, N) {
        int C, P;
        cin >> C >> P;

        if (C == 1) {
            S1[i] = P;
            S2[i] = 0;
        } else {
            S1[i] = 0;
            S2[i] = P;
        }
    }
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }

    vector<int> sum1(N + 1), sum2(N + 1);
    rep(i, N) {
        sum1[i + 1] = sum1[i] + S1[i];
        sum2[i + 1] = sum2[i] + S2[i];
    }

    rep(i, Q) {
        cout << sum1[R[i] + 1] - sum1[L[i]] << " " << sum2[R[i] + 1] - sum2[L[i]] << endl;
    }
}