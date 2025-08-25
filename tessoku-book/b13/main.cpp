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
    int l = 0, r = -1, sum = 0;
    int cnt = 0;
    while (l < N) {
        while (sum + A[r + 1] <= K) r++, sum += A[r];
        if (sum >= 0 && sum <= K) cnt += r - l + 1;
        sum -= A[l];
        l++;
    }
    cout << cnt << endl;
}
