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

    set<int> s;
    rep(i, N) s.insert(i + 1);

    rep(i, M) s.erase(A[i]);

    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}
