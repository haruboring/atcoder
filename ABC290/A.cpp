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
    vector<int> A(N), B(M);
    rep(i, N) {
        cin >> A[i];
    }
    int sum_point = 0;
    rep(i, M) {
        int b;
        cin >> b;
        sum_point += A[b - 1];
    }
    cout << sum_point << endl;
}