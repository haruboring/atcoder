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
    int Q;
    cin >> Q;
    vector<int> flag(Q), x(Q), y(Q);
    rep(i, Q) {
        cin >> flag[i];
        cin >> x[i];
        if (flag[i] == 1) {
            cin >> y[i];
        }
    }

    map<int, list<int>::iterator> mp;
    list<int> ls;
    rep(i, N) {
        ls.push_back(A[i]);
        auto itr = ls.begin();
        advance(itr, i);
        mp[A[i]] = prev(ls.end());
    }

    rep(i, Q) {
        if (flag[i] == 1) {
            auto it = mp[x[i]];
            advance(it, 1);
            auto itr = ls.insert(it, y[i]);
            mp[y[i]] = itr;
        } else if (flag[i] == 2) {
            auto it = mp[x[i]];
            ls.erase(it);
            mp.erase(x[i]);
        }
    }

    for (int a : ls) {
        cout << a << " ";
    }
    cout << endl;
}
