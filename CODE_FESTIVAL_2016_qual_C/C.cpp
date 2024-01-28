// #include "atcoder/all"
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
    vector<int> T(N), A(N);
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];

    vector<bool> correct(N, false);
    correct[0] = true;
    rep(i, N - 1) {
        if (T[i + 1] > T[i]) {
            correct[i + 1] = true;
        }
    }

    if (correct[N - 1]) {
        if (A[N - 1] != T[N - 1]) {
            cout << 0 << endl;
            return 0;
        }
    }

    correct[N - 1] = true;
    if (A[N - 1] > T[N - 1]) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    int MOD = 1e9 + 7;
    for (int i = N - 1; i >= 1; i--) {
        if (A[i - 1] > A[i]) {
            if (correct[i - 1]) {
                if (A[i - 1] != T[i - 1]) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                ans *= 1;
            }
        } else {
            if (correct[i - 1]) {
                if (A[i - 1] < T[i - 1]) {
                    cout << 0 << endl;
                    return 0;
                }
                ans *= 1;
            } else {
                ans *= min(A[i - 1], T[i - 1]);
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}