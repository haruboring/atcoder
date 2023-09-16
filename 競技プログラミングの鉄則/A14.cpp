#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }
    rep(i, N) {
        cin >> C[i];
    }
    rep(i, N) {
        cin >> D[i];
    }
    vector<int> AB(0), CD(0);
    rep(i, N) {
        rep(j, N) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }
    sort(all(CD));
    rep(i, N * N) {
        if (binary_search(CD.begin(), CD.end(), K - AB[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}