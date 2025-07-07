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
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '1') s.insert(i);
        if (T[i] == '1') t.insert(i);
        if (t.size() > s.size()) {
            cout << -1 << endl;
            return 0;
        }
    }
    if ((s.size() - t.size()) % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    while ((s.size() > 0) && (t.size() > 0)) {
        int sb1 = *s.begin();
        int tb1 = *t.begin();
        if (sb1 < tb1) {
            s.erase(sb1);
            int sb2 = *s.begin();
            s.erase(sb2);
            cnt += sb2 - sb1;
        } else {
            cnt += sb1 - tb1;
            s.erase(sb1);
            t.erase(tb1);
        }
    }
    while (s.size() > 0) {
        int sb1 = *s.begin();
        s.erase(sb1);
        int sb2 = *s.begin();
        s.erase(sb2);

        cnt += sb2 - sb1;
    }

    cout << cnt << endl;
}
