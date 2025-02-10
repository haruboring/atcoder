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
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];

    map<int, int> m;
    rep(i, N) m[Q[i]] = i;
    map<int, int> rm;
    rep(i, N) rm[i] = Q[i];
    rep(i, N) {
        int a = m[i + 1];
        int b = P[a];
        cout << rm[b - 1] << " ";
    }
    cout << endl;
}
