#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int st = A[0];
    map<int, int> mp;
    rep(i, N - 1) {
        if (A[i + 1] < A[i]) {
            mp[A[i] - st]++;
            if (A[i + 1] < st) st = A[i + 1];
            debug(st);
        }
        if (i == N - 2 && A[i + 1] >= A[i]) {
            mp[A[i + 1] - st]++;
        }
    }

    int max_diff = -1;
    for (auto p : mp) {
        max_diff = max(max_diff, p.first);
    }

    debug(max_diff);

    cout << mp[max_diff] << endl;
}
