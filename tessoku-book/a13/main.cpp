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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    A.push_back(1e18);
    int cnt = 0;
    int l = 0, r = -1;
    while (l < N) {
        while (A[r + 1] - A[l] <= K) r++;
        cnt += r - l;
        l++;
    }
    cout << cnt << endl;
}
