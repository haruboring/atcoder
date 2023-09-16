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
    vector<int> A(N), cut(N + 1);
    ll sum_digree = 0;
    cut[0] = 0;
    rep(i, N) {
        cin >> A[i];
        sum_digree += A[i];
        cut[i + 1] = sum_digree % 360;
    }
    sort(all(cut));
    int max_cut_digree = -1;
    rep(i, N + 10) {
        max_cut_digree = max(max_cut_digree, (cut[(i+1) % (N + 1)] - cut[i % (N + 1)] + 360) % 360);
    }
    cout << max_cut_digree << endl;
}