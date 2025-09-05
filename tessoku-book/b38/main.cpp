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
    string S;
    cin >> S;

    vector<int> A(N, 1);
    int t = 1;
    rep(i, N - 1) {
        if (S[i] == 'A') {
            A[i + 1] = t + 1;
            t++;
        } else {
            t = 1;
        }
    }

    t = 1;
    for (int i = N - 2; i >= 0; i--) {
        if (S[i] == 'B') {
            A[i] = max(A[i], t + 1);
            t++;
        } else {
            t = 1;
        }
    }

    cout << accumulate(all(A), 0LL) << endl;
}
