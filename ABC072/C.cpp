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
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> m(a[N - 1] + 1);
    rep(i, N) {
        m[a[i]]++;
    }
    int current_cnt = m[0] + m[1] + m[2];
    int max_cnt = current_cnt;
    rep(i, a[N - 1] - 2) {
        current_cnt += m[i + 3] - m[i];
        max_cnt = max(max_cnt, current_cnt);
    }
    cout << max_cnt << endl;
}