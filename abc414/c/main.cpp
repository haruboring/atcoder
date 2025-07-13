#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int A, N;
vector<int> keta, keta_;
int cnt = 0, sum = 0;

void dfs(string s) {
    int n = s.size();

    // zxz
    if (2 * n - 1 > keta.size()) return;
    int tmp = keta[n - 1] * (s[n - 1] - '0');
    // debug(tmp);
    rep(i, n - 1) {
        int ci = s[i] - '0';
        tmp += keta[i] * ci + keta[2 * n - 2 - i] * ci;
    }
    if (tmp <= N) {
        string ts = to_string(tmp);
        bool ok = true;
        rep(i, ts.size()) if (ts[i] != ts[ts.size() - 1 - i]) ok = false;
        if (ok) cnt++, sum += tmp;
    }

    // xzzx
    if (2 * n > keta.size()) return;
    tmp = 0;
    rep(i, n) {
        int ci = s[i] - '0';
        tmp += keta[i] * ci + keta[2 * n - 1 - i] * ci;
    }
    if (tmp <= N) {
        // debug(s);
        string ts = to_string(tmp);
        bool ok = true;
        rep(i, ts.size()) if (ts[i] != ts[ts.size() - 1 - i]) ok = false;
        if (ok) cnt++, sum += tmp;
        // debug(tmp);
    }

    rep(i, A) dfs(s + to_string(i));
}

signed main() {
    cin >> A >> N;
    int tmp = 1;
    while (tmp <= N) {
        keta.push_back(tmp);
        tmp *= A;
    }

    tmp = 1;
    rep(i, 13) {
        keta_.push_back(tmp);
        tmp *= 10;
    }

    rep(i, A - 1) dfs(to_string(i + 1));
    cout << sum << endl;
    debug(cnt);
}
