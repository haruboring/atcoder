#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    rep(_, T) {
        ll N, K;
        cin >> N >> K;

        ll ma = N;
        ll max_n = 1;
        while (max_n <= N) {
            max_n *= 3;
        }
        if (N != 1) max_n /= 3;

        ll mi = 0;
        while (N > 0) {
            if (N >= max_n) {
                mi += N / max_n;
                N -= max_n * (N / max_n);
            }
            max_n /= 3;
        }

        debug(0);
        debug(mi);
        debug(ma);
        if (mi <= K && K <= ma && (K - mi) % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}