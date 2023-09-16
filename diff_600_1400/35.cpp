#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> al(0);
    rep(i, N) {
        rep(j, A[i]) {
            al.push_back(i + 1);
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (i % 2 == 0) {
                cout << al[i * W + j] << " ";
            } else {
                cout << al[i * W + (W - j - 1)] << " ";
            }
        }
        cout << endl;
    }
}