#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    vector<int> L(M), R(M);
    rep(i, M) cin >> L[i] >> R[i];

    vector<int> s(N + 1);
    rep(i, M) s[L[i] - 1]++, s[R[i]]--;

    string aS = "";
    rep(i, N) s[i + 1] += s[i];
    rep(i, N) {
        if (s[i] % 2 == 0) {
            aS += S[i];
        } else {
            aS += T[i];
        }
    }
    cout << aS << endl;
}
