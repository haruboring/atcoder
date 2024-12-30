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
    vector<int> K(N);

    set<int> s;
    rep(i, M) s.insert(i + 1);

    rep(_, N) {
        int K;
        cin >> K;

        set<int> m;
        rep(i, K) {
            int A;
            cin >> A;
            m.insert(A);
        }

        set<int> ans;
        set_intersection(all(s), all(m), inserter(ans, ans.end()));
        s = ans;
    }

    cout << s.size() << endl;
}
