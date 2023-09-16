#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, W;
    cin >> N >> W;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    set<int> S;
    sort(all(A));
    rep(i, N) {
        if (A[i] <= W) {
            S.insert(A[i]);
        }
    }
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            if (A[i] + A[j] <= W) {
                S.insert(A[i] + A[j]);
            }
        }
    }
    rep(i, N - 2) {
        repp(j, i + 1, N - 1) {
            repp(k, j + 1, N) {
                if (A[i] + A[j] + A[k] <= W) {
                    S.insert(A[i] + A[j] + A[k]);
                }
            }
        }
    }
    cout << S.size() << endl;
}