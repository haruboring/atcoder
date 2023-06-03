#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> A(N);
    rep(i, N) cin >> S[i] >> A[i];

    int m = 1e9 + 10;
    rep(i, N) {
        m = min(m, A[i]);
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == m) {
            rep(j, N) {
                cout << S[(i + j) % N] << endl;
            }
            return 0;
        }
    }
}