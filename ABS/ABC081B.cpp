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
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<int> cnt(N);
    rep(i, N) {
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            cnt[i]++;
        }
    }
    sort(all(cnt));
    cout << cnt[0] << endl;
}