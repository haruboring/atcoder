#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> h(N), w(N), d(N);
    rep(i, N) cin >> h[i] >> w[i] >> d[i];

    vector<int> sm(N), md(N), lg(N);
    set<int> ss, mm, ll;
    rep(i, N) {
        vector<int> tmp(3);
        tmp[0] = h[i];
        tmp[1] = w[i];
        tmp[2] = d[i];
        sort(all(tmp));
        sm[i] = tmp[0];
        md[i] = tmp[1];
        lg[i] = tmp[2];
        ss.insert(sm[i]);
        mm.insert(md[i]);
        ll.insert(lg[i]);
    }

    map<int, int> zyuni_s, zyuni_m, zyuni_l;
    int cnt = 0;
    for (int s : ss) {
        zyuni_s[s] = cnt;
        cnt++;
    }
    cnt = 0;
    for (int m : mm) {
        zyuni_m[m] = cnt;
        cnt++;
    }
    cnt = 0;
    for (int l : ll) {
        zyuni_l[l] = cnt;
        cnt++;
    }

    vector<int> h_order(N), w_order(N), d_order(N);
    rep(i, N) {
        h_order[i] = zyuni_s[sm[i]];
        w_order[i] = zyuni_m[md[i]];
        d_order[i] = zyuni_l[lg[i]];
    }

    vector<tuple<int, int, int>> order(N);
    rep(i, N) {
        order[i] = make_tuple(h_order[i], w_order[i], d_order[i]);
    }
    sort(all(order));

    multiset<int> s, m, l;
    rep(i, N) {
        s.insert(h_order[i]);
        m.insert(w_order[i]);
        l.insert(d_order[i]);
    }

    rep(i, N - 1) {
        int order_s = h_order[i];
        int order_m = w_order[i];
        int order_l = d_order[i];

        s.erase(s.find(order_s));
        m.erase(m.find(order_m));
        l.erase(l.find(order_l));
        if (order_s < *begin(s) && order_m < *begin(m) && order_l < *begin(l)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}