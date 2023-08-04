#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    vector<int> st(10);
    rep(i, 10) cin >> st.at(i);

    int ans = 0;
    rep(_, 3) {
        ans = st[ans];
    }
    cout << ans << endl;
}