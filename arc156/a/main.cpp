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
        int N;
        cin >> N;
        string S;
        cin >> S;

        if (S == "011" || S == "110") {
            cout << -1 << endl;
            continue;
        }
        if (S == "0110") {
            cout << 3 << endl;
            continue;
        }

        set<int> s;
        rep(i, N) if (S[i] == '1') s.insert(i);

        if (s.size() % 2) {
            cout << -1 << endl;
            continue;
        }
        if (s.size() == 2) {
            int a = *s.begin();
            int b = *s.rbegin();
            if (a + 1 == b) {
                cout << 2 << endl;
                continue;
            }
        }
        cout << s.size() / 2 << endl;
    }
}
