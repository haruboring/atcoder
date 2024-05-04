#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    rep(i, N) cin >> C[i];
    vector<int> A(Q), B(Q);
    rep(i, Q) cin >> A[i] >> B[i];

    rep(i, Q) A[i]--, B[i]--;

    vector<set<int>> colors(N);
    rep(i, N) colors[i].insert(C[i]);

    map<int, int> mp;
    rep(i, N) mp[i] = i;

    rep(i, Q) {
        if (colors[mp[A[i]]].size() < colors[mp[B[i]]].size()) {
            colors[mp[B[i]]].insert(all(colors[mp[A[i]]]));
            colors[mp[A[i]]].clear();
        } else {
            colors[mp[A[i]]].insert(all(colors[mp[B[i]]]));
            colors[mp[B[i]]].clear();
            swap(mp[A[i]], mp[B[i]]);
        }

        cout << colors[mp[B[i]]].size() << endl;
    }
}