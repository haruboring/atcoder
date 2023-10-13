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
    vector<int> A(N + 1), B(N + 1), C(N + 1);
    rep(i, N) cin >> A.at(i + 1);
    rep(i, N) cin >> B.at(i + 1);
    rep(i, N) cin >> C.at(i + 1);

    map<int, int> mpb;
    rep(i, N) {
        mpb[B.at(C.at(i + 1))]++;
    }

    map<int, int> mpa;
    rep(i, N) {
        mpa[A.at(i + 1)]++;
    }

    int cnt = 0;
    rep(i, N + 1) {
        cnt += mpa[i] * mpb[i];
    }

    cout << cnt << endl;
}