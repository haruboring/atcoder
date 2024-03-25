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

    int ans = N;
    set<int> s;
    repp(i, 2, sqrt(N) + 1) {
        for (int j = 2; pow(i, j) <= N; j++) {
            s.insert(pow(i, j));
        }
    }

    cout << ans - s.size() << endl;
}