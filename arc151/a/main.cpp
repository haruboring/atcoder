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
    string S, T;
    cin >> S >> T;

    set<int> s, t;
    rep(i, N) {
        if (S[i] == T[i]) continue;
        if (S[i] == '1') s.insert(i);
        if (T[i] == '1') t.insert(i);
    }

    if (s.size() < t.size()) swap(s, t);

    if ((s.size() - t.size()) % 2) {
        cout << -1 << endl;
        return 0;
    }

    string U = "";
    rep(i, N) U += "0";
    while (s.size() != t.size()) {
        int i = *s.rbegin();
        s.erase(i);
        U[i] = '1';
        t.insert(i);
    }

    cout << U << endl;
}
