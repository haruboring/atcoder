#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;

    multiset<int> s;
    vector<int> buf;
    int buf_idx = 0;
    rep(i, Q) {
        int f;
        cin >> f;

        if (f == 1) {
            int x;
            cin >> x;
            buf.push_back(x);
        } else if (f == 3) {
            repp(j, buf_idx, buf.size()) s.insert(buf[j]);
            buf.clear();
            buf_idx = 0;
        } else {
            if (s.size() == 0) {
                cout << buf[buf_idx] << endl;
                buf_idx++;
                continue;
            }
            int f = *s.begin();
            s.erase(s.find(f));
            cout << f << endl;
        }
    }
}
