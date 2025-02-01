#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;

    map<int, int> cnt, m;
    rep(i, N) cnt[i + 1] = 1;
    rep(i, N) m[i + 1] = i + 1;
    set<int> ms;

    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 2) {
            cout << ms.size() << endl;
        } else {
            int p, h;
            cin >> p >> h;

            int from_su = m[p];
            if (cnt[from_su] == 2) {
                ms.erase(from_su);
            }
            cnt[from_su]--;
            cnt[h]++;
            if (cnt[h] == 2) {
                ms.insert(h);
            }
            m[p] = h;
        }
    }
}
