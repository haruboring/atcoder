#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    rep(_, T) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(N);
        rep(i, N) cin >> A[i];
        rep(i, N) cin >> B[i];

        multiset<int> sA;
        rep(i, N) sA.insert(A[i]);
        sA.insert(1e18);
        int s = 0;
        rep(i, N) {
            int a = *sA.lower_bound(M - B[i]);
            if (a == 1e18) a = *sA.begin();
            s += (a + B[i]) % M;
            sA.erase(sA.find(a));
        }

        cout << s << endl;
    }
}
