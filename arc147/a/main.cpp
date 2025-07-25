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

    multiset<int> s;
    rep(i, N) s.insert(A[i]);

    int cnt = 0;
    while (s.size() > 1) {
        int ma = *s.rbegin();
        int mi = *s.begin();
        cnt++;

        s.erase(s.find(ma));
        if (ma % mi == 0) continue;
        s.insert(ma % mi);
    }

    cout << cnt << endl;
}
