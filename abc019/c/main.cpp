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

    vector<int> B(0);
    int t = 2;
    while (t < 1e9 + 1000) {
        B.push_back(t);
        t *= 2;
    }

    debug(B.size());

    sort(all(A));
    int cnt = 0;
    set<int> s;
    for (int a : A) {
        bool sk = false;
        for (int b : B) {
            if ((a % b == 0) && (s.count(a / b))) {
                sk = true;
                break;
            }
        }
        if (sk) continue;
        cnt++;
        s.insert(a);
    }

    cout << cnt << endl;
}
