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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A[i]--;

    set<int> called;

    rep(i, N) {
        if (called.count(i)) continue;
        called.insert(A[i]);
    }

    cout << N - called.size() << endl;
    rep(i, N) {
        if (called.count(i)) continue;
        cout << i + 1 << " ";
    }
    cout << endl;
}