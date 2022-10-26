#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll> A(N - 1), X(M), Y(M);
    rep(i, N - 1) {
        cin >> A[i];
    }
    rep(i, M) {
        cin >> X[i] >> Y[i];
    }
    rep(i, M) {
        A[X[i] - 1] -= Y[i];
    }
    ll step = 0, time = T;
    bool reached_N = false;
    while (1) {
        if (step == N - 1) {
            reached_N = true;
            break;
        }
        if (time > A[step]) {
            time -= A[step];
            step++;
        } else {
            break;
        }
    }
    if (reached_N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}