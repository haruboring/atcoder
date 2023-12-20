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

    vector<int> repunit(0);

    int tmp = 0;
    rep(i, 16) {
        tmp = tmp * 10 + 1;
        repunit.push_back(tmp);
    }

    vector<int> wa(0);
    rep(i, 16) {
        rep(j, 16) {
            rep(k, 16) {
                wa.push_back(repunit[i] + repunit[j] + repunit[k]);
            }
        }
    }

    set<int> s(all(wa));

    int cnt = 0;
    for (auto x : s) {
        cnt++;
        if (cnt == N) {
            cout << x << endl;
            return 0;
        }
    }
}
