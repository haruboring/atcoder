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
    set<int> s;
    rep(_, K) {
        int d;
        cin >> d;
        rep(_, d) {
            int A;
            cin >> A;
            s.insert(A);
        }
    }

    cout << N - s.size() << endl;
}
