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
    vector<int> A(M);
    rep(i, M) cin >> A[i];

    vector<int> cnt(N + 2);
    int winner = N + 1;

    rep(i, M) {
        cnt[A[i]]++;
        if (cnt[A[i]] >= cnt[winner]) {
            if (!(cnt[A[i]] == cnt[winner] && A[i] > winner)) winner = A[i];
        }
        cout << winner << endl;
    }
}
