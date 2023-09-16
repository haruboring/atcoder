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
    map<int, multiset<int>> date_earn;
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        date_earn[A].insert(B);
    }

    int ans = 0;
    multiset<int> earns;
    repp(date, 1, M + 1) {
        for (auto earn : date_earn[date]) {
            earns.insert(earn);
        }
        if (earns.size() != 0) {
            ans += *rbegin(earns);
            earns.erase(earns.find(*rbegin(earns)));
        }
    }
    cout << ans << endl;
}