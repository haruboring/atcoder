#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<vector<int>> A(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> A[i][j];

    set<tuple<int, int, int>> Aij;
    rep(i, 3) rep(j, 3) Aij.insert({A[i][j], i, j});
    int a_score = 0, t_score = 0;
    vector<vector<int>> cA(3, vector<int>(3, -1));
    rep(i, 9) {
        bool cn = false;
        for (int s = 0; s < 3; s++) {
            if (cn) break;
            for (int skipt = 0; skipt < 3; skipt++) {
                if (cn) break;
                set<int> st;
                for (int t = 0; t < 3; t++) {
                    if (t == skipt) continue;
                    st.insert(cA[s][t]);
                }
                if (cA[s][skipt] == -1 && st.size() == 1 && *st.begin() == (i + 1) % 2) {
                    int aaa = A[s][skipt];

                    if (i % 2 == 0) {
                        t_score += aaa;
                        cA[s][skipt] = 0;
                    } else {
                        a_score += aaa;
                        cA[s][skipt] = 1;
                    }
                    Aij.erase({A[s][skipt], s, skipt});
                    cn = true;
                }
                if (cn) break;
            }
            if (cn) break;
        }
        if (cn) continue;

        for (int t = 0; t < 3; t++) {
            if (cn) break;
            for (int skipt = 0; skipt < 3; skipt++) {
                if (cn) break;
                set<int> st;
                for (int s = 0; s < 3; s++) {
                    if (s == skipt) continue;
                    st.insert(cA[s][t]);
                }
                if (cA[skipt][t] == -1 && st.size() == 1 && *st.begin() == (i + 1) % 2) {
                    int aaa = A[skipt][t];

                    if (i % 2 == 0) {
                        t_score += aaa;
                        cA[skipt][t] = 0;
                    } else {
                        a_score += aaa;
                        cA[skipt][t] = 1;
                    }
                    Aij.erase({A[skipt][t], skipt, t});
                    cn = true;
                }
                if (cn) break;
            }
            if (cn) break;
        }
        if (cn) continue;

        vector<pair<int, int>> tmp = {{0, 0}, {1, 1}, {2, 2}};
        for (int skipt = 0; skipt < 3; skipt++) {
            set<int> st;
            for (int t = 0; t < 3; t++) {
                if (t == skipt) continue;
                st.insert(cA[t][t]);
            }
            if (cA[skipt][skipt] == -1 && st.size() == 1 && *st.begin() == (i + 1) % 2) {
                int aaa = A[skipt][skipt];

                if (i % 2 == 0) {
                    t_score += aaa;
                    cA[skipt][skipt] = 0;
                } else {
                    a_score += aaa;
                    cA[skipt][skipt] = 1;
                }
                Aij.erase({aaa, skipt, skipt});
                cn = true;
            }
            if (cn) break;
        }
        if (cn) continue;

        vector<pair<int, int>> tmp2 = {{0, 2}, {1, 1}, {2, 0}};
        for (int skipt = 0; skipt < 3; skipt++) {
            set<int> st;
            for (int t = 0; t < 3; t++) {
                if (t == skipt) continue;
                st.insert(cA[tmp2[t].first][tmp2[t].second]);
            }
            if (cA[tmp2[skipt].first][tmp2[skipt].second] == -1 && st.size() == 1 && *st.begin() == (i + 1) % 2) {
                int aaa = A[tmp2[skipt].first][tmp2[skipt].second];

                if (i % 2 == 0) {
                    t_score += aaa;
                    cA[tmp2[skipt].first][tmp2[skipt].second] = 0;
                } else {
                    a_score += aaa;
                    cA[tmp2[skipt].first][tmp2[skipt].second] = 1;
                }
                Aij.erase({aaa, tmp2[skipt].first, tmp2[skipt].second});
                cn = true;
            }
            if (cn) break;
        }
        if (cn) continue;

        auto [a, x, y] = *Aij.rbegin();
        if (i % 2 == 0) {
            t_score += a;
            cA[x][y] = 0;
        } else {
            a_score += a;
            cA[x][y] = 1;
        }
        Aij.erase({a, x, y});
    }

    if (t_score > a_score) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
