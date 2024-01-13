#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ofstream file("output.txt");

    int N, M;
    cin >> N >> M;
    int si, sj;
    cin >> si >> sj;
    vector<vector<char>> A(N, vector<char>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    vector<string> t(M);
    rep(i, M) cin >> t[i];

    set<string> st;
    rep(i, M) st.insert(t[i]);
    vector<string> sorted_t;
    for (auto s : st) sorted_t.push_back(s);
    t = sorted_t;
    M = t.size();

    map<char, vector<pair<int, int>>> mp;
    rep(i, N) rep(j, N) mp[A[i][j]].push_back({i, j});

    int ni = si, nj = sj;
    rep(i, M) {
        int del_idx = -1;
        int dist = 1e9;
        int next_i, next_j;
        rep(j, M) {
            if (t[j] == "") continue;
            char c = t[j][0];
            int n_ni = mp[c][0].first, n_nj = mp[c][0].second;
            for (auto p : mp[c]) {
                if (abs(ni - p.first) + abs(nj - p.second) < abs(ni - n_ni) + abs(nj - n_nj)) {
                    n_ni = p.first;
                    n_nj = p.second;
                }
            }

            if (abs(ni - n_ni) + abs(nj - n_nj) < dist) {
                dist = abs(ni - n_ni) + abs(nj - n_nj);
                next_i = n_ni;
                next_j = n_nj;
                del_idx = j;
            }
        }

        string sorted_ti = t[del_idx];
        t[del_idx] = "";

        for (auto c : sorted_ti) {
            int n_si = mp[c][0].first, n_sj = mp[c][0].second;
            for (auto p : mp[c]) {
                if (abs(si - p.first) + abs(sj - p.second) < abs(si - n_si) + abs(sj - n_sj)) {
                    n_si = p.first;
                    n_sj = p.second;
                }
            }

            si = n_si;
            sj = n_sj;
            cout << si << " " << sj << endl;
            file << si << " " << sj << endl;
        }
        ni = si;
        nj = sj;
    }

    file.close();
}