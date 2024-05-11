#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;
    map<char, int> cnt_s, cnt_t;
    set<char> all;
    int cnt_wild_s = 0, cnt_wild_t = 0;
    rep(i, S.size()) {
        cnt_s[S[i]]++;
        cnt_t[T[i]]++;
        if (S[i] == '@') {
            cnt_wild_s++;
        }
        if (T[i] == '@') {
            cnt_wild_t++;
        }
        all.insert(T[i]);
        all.insert(S[i]);
    }

    set<char> atc;
    atc.insert('a');
    atc.insert('t');
    atc.insert('c');
    atc.insert('o');
    atc.insert('d');
    atc.insert('e');
    atc.insert('r');
    int cnt = 0;
    int sw_cnt = 0, tw_cnt = 0;
    for (auto c : all) {
        if (c == '@') continue;
        if (atc.count(c) == 0) {
            if (cnt_t[c] != cnt_s[c]) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            // cout << cnt_s[c] << " " << s.second << " , " << cnt_t[s.first] << endl;
            cnt += cnt_t[c] - cnt_s[c];
            sw_cnt += max(0LL, cnt_t[c] - cnt_s[c]);
            tw_cnt += max(0LL, cnt_s[c] - cnt_t[c]);
        }
    }

    if (cnt == cnt_wild_s - cnt_wild_t && sw_cnt <= cnt_wild_s && tw_cnt <= cnt_wild_t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}