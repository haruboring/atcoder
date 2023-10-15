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
    string S;
    cin >> S;

    map<char, int> mp;
    rep(i, N) {
        mp[S[i]]++;
    }

    set<string> heiho;
    for (int i = 0; i * i < 1e13 + 100; i++) {
        string s = to_string(i * i);
        heiho.insert(string(max(0LL, N - (int)s.size()), '0') + s);
    }

    int cnt = 0;

    for (auto a : heiho) {
        if (a.size() > N) continue;
        map<char, int> mp2;
        rep(i, a.size()) {
            mp2[a[i]]++;
        }
        bool ok = true;
        for (auto b : mp) {
            if (mp2[b.first] != b.second) {
                ok = false;
                break;
            }
        }

        for (auto b : mp2) {
            if (mp[b.first] != b.second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt++;
        }
    }

    cout << cnt << endl;
}