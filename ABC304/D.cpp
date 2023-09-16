#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int W, H;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> p(N), q(N);
    rep(i, N) cin >> p[i] >> q[i];
    int A;
    cin >> A;
    vector<int> a(A);
    rep(i, A) cin >> a[i];
    int B;
    cin >> B;
    vector<int> b(B);
    rep(i, B) cin >> b[i];

    map<pair<int, int>, int> mp;
    rep(i, N) {
        int xp = lower_bound(all(a), p[i]) - a.begin();
        int yp = lower_bound(all(b), q[i]) - b.begin();
        mp[make_pair(xp, yp)]++;
    }

    vector<int> num(0);
    for (auto x : mp) {
        num.push_back(x.second);
    }
    sort(all(num));
    if (num.size() == (A + 1) * (B + 1)) {
        cout << num[0] << " " << num[num.size() - 1] << endl;
    } else {
        cout << 0 << " " << num[num.size() - 1] << endl;
    }
}