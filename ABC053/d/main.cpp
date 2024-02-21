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
    rep(i, N) cin >> A[i];

    set<int> s;
    int dup_cnt = 0;
    rep(i, N) {
        if (s.count(A[i])) {
            dup_cnt++;
        }
        s.insert(A[i]);
    }

    if (dup_cnt % 2 == 0) {
        cout << s.size() << endl;
    } else {
        cout << s.size() - 1 << endl;
    }
}
