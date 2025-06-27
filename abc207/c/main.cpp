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
    vector<double> L(N), R(N);
    rep(i, N) {
        int t;
        cin >> t >> L[i] >> R[i];

        if (t == 2) {
            R[i] -= 0.1;
        } else if (t == 3) {
            L[i] += 0.1;
        } else if (t == 4) {
            R[i] -= 0.1;
            L[i] += 0.1;
        }
    }

    int cnt = 0;
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            if ((L[i] <= R[j]) && (R[i] >= L[j])) {
                cnt++;
            } else if ((L[j] <= R[i]) && (R[j] >= L[i])) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
