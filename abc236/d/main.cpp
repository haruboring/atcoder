#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int cnt = 0;
vector<int> v;
vector<vector<int>> res;
set<int> st;
void dfs() {
    if (st.size() == 0) {
        res.push_back(v);
        cnt++;
        return;
    }
    vector<pair<vector<int>, set<int>>> q;
    int b = *st.begin();
    st.erase(b);
    v.push_back(b);
    set<int> tmp = st;
    for (auto x : tmp) {
        st.erase(x);
        v.push_back(x);
        dfs();
        v.pop_back();
        st.insert(x);
    }
    v.pop_back();
    st.insert(b);
    return;
}

signed main() {
    int N;
    cin >> N;
    map<pair<int, int>, int> mp;
    rep(i, 2 * N - 1) {
        repp(j, i + 1, 2 * N) {
            int a;
            cin >> a;
            mp[{i, j}] = a;
        }
    }

    rep(i, 2 * N) st.insert(i);
    dfs();
    debug(cnt);
    vector<vector<int>> orders = res;
    debug(orders.size());
    int ans = 0;
    rep(ii, orders.size()) {
        vector<int> a;
        rep(i, N) {
            int s = orders[ii][2 * i];
            int t = orders[ii][2 * i + 1];
            if (s > t) swap(s, t);
            a.push_back(mp[{s, t}]);
        }

        int tmp = 0;
        vector<int> bit(31);
        rep(i, N) {
            int x = a[i];
            rep(j, 31) {
                if (x & (1LL << j)) bit[j]++;
            }
        }
        rep(i, 31) {
            if (bit[i] % 2 == 1) tmp += (1LL << i);
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
