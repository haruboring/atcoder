// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int get_score(vector<tuple<int, int, int, int>> ans, int L) {
    int N = 1000;  // N=1000
    int C = 0;
    for (auto [x, y, x_new, y_new] : ans) {
        C += (x_new - x) + (y_new - y);
    }
    int score = round(1e6 * (N * L) / (1.0 + (double)C));
    return score;
}

signed main() {
    int N;
    cin >> N;  // N=1000
    vector<pair<int, int>> AB(N);
    rep(i, N) cin >> AB[i].first >> AB[i].second;

    int L = -1;
    rep(i, N) L = max(L, AB[i].first + AB[i].second);
    vector<vector<tuple<int, int, int, int>>> anses(3);

    // 並び替えなし: 0
    set<pair<int, int>> st;
    st.insert({0, 0});

    rep(i, N) {
        auto [a, b] = AB[i];
        int mc = a - 0 + b - 0;
        pair<int, int> p = {0, 0};

        for (auto [pa, pb] : st) {
            if (a > pa && b > pb) {
                if (mc > (a - pa) + (b - pb)) {
                    mc = (a - pa) + (b - pb);
                    p = {pa, pb};
                }
            }
        }

        anses[0].push_back({p.first, p.second, a, b});
        st.insert({a, b});
    }

    // 並び替えあり, xについて昇順: 1
    sort(all(AB));

    st.clear();
    st.insert({0, 0});

    rep(i, N) {
        auto [a, b] = AB[i];
        int mc = a - 0 + b - 0;
        pair<int, int> p = {0, 0};

        for (auto [pa, pb] : st) {
            if (a > pa && b > pb) {
                if (mc > (a - pa) + (b - pb)) {
                    mc = (a - pa) + (b - pb);
                    p = {pa, pb};
                }
            }
        }

        anses[1].push_back({p.first, p.second, a, b});
        st.insert({a, b});
    }

    // 並び替えあり, yについて昇順: 2
    sort(all(AB), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second; });

    st.clear();
    st.insert({0, 0});

    rep(i, N) {
        auto [a, b] = AB[i];
        int mc = a - 0 + b - 0;
        pair<int, int> p = {0, 0};

        for (auto [pa, pb] : st) {
            if (a > pa && b > pb) {
                if (mc > (a - pa) + (b - pb)) {
                    mc = (a - pa) + (b - pb);
                    p = {pa, pb};
                }
            }
        }

        anses[2].push_back({p.first, p.second, a, b});
        st.insert({a, b});
    }

    int idx = 0;
    int score = get_score(anses[0], L);
    rep(i, 3) {
        int s = get_score(anses[i], L);
        if (s > score) {
            score = s;
            idx = i;
        }
    }

    cout << anses[idx].size() << endl;
    for (auto [a, b, c, d] : anses[idx]) cout << a << " " << b << " " << c << " " << d << endl;
}