#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    bool one = false;
    int m = -1;
    rep(i, N) {
        cin >> C[i];
        if (C[i] == T) {
            one = true;
        }
    }
    if (one == false) {
        T = C[0];
    }
    rep(i, N) {
        cin >> R[i];
        if (C[i] == T) {
            m = max(m, R[i]);
        }
    }

    rep(i, N) {
        if (C[i] == T && R[i] == m) {
            cout << i + 1 << endl;
        }
    }
}