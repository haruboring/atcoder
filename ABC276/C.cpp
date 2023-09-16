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
    vector<int> P(N);
    rep(i, N) {
        cin >> P[i];
    }
    vector<int> ch(0), co(0);
    rep(i, N - 1) {
        if (P[N - 1 - i] > P[N - 2 - i]) {
            ch.push_back(P[N - 1 - i]);
        } else {
            ch.push_back(P[N - 1 - i]);
            ch.push_back(P[N - 2 - i]);
            break;
        }
    }
    rep(i, ch.size()) {
        co.push_back(ch[i]);
    }
    int st = co[co.size() - 1], mi;
    sort(all(co));
    rep(i, co.size()) {
        if (co[i] < st) {
            mi = co[i];
        }
    }
    reverse(all(co));
    rep(i, N - ch.size()) {
        cout << P[i] << " ";
    }
    cout << mi << " ";
    rep(i, co.size()) {
        if (co[i] == mi) {
            continue;
        } else {
            cout << co[i] << " ";
        }
    }
    cout << endl;
}