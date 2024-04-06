#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> D(N);
    rep(i, N) cin >> D[i];

    set<int> ss, ss1;
    rep(i, N) {
        ss.insert(D[i] % (A + B));
        ss1.insert((D[i] + A) % (A + B));
    }

    int diff = *ss.rbegin() - *ss.begin();
    int diff1 = *ss1.rbegin() - *ss1.begin();
    if (diff <= A - 1 || diff1 <= A - 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
