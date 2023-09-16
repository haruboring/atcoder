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
    vector<int> X(N), cX(N);
    rep(i, N) {
        cin >> X[i];
    }
    cX = X;
    sort(all(X));
    int r = X[N / 2], l = X[N / 2 - 1];
    rep(i, N) {
        if (cX[i] < r) {
            cout << r << endl;
        } else {
            cout << l << endl;
        }
    }
}