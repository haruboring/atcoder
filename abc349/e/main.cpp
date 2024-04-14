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

    vector<pair<int, int>> orders = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    sort(all(orders));

    vector<vector<int>> cA(3, vector<int>(3, -1));

    map<pair<int, int>, set<int>> t_select_ans;

    do {
        vector<vector<int>> cA(3, vector<int>(3, -1));
        bool ok = true;
        int t_score = 0, a_score = 0;
        bool skip = false;
        rep(i, 9) {
            auto [x, y] = orders[i];
            cA[x][y] = i % 2;
            if (i % 2 == 0) {
                t_score += A[x][y];
            } else {
                a_score += A[x][y];
            }

            // 0 -> T

            if (cA[0][0] == cA[0][1] && cA[0][1] == cA[0][2] && cA[0][2] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[0][0]);
                skip = true;
                break;
            }
            if (cA[1][0] == cA[1][1] && cA[1][1] == cA[1][2] && cA[1][2] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[1][0]);
                skip = true;
                break;
            }
            if (cA[2][0] == cA[2][1] && cA[2][1] == cA[2][2] && cA[2][2] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[2][0]);
                skip = true;
                break;
            }
            if (cA[0][0] == cA[1][0] && cA[1][0] == cA[2][0] && cA[2][0] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[0][0]);
                skip = true;
                break;
            }
            if (cA[0][1] == cA[1][1] && cA[1][1] == cA[2][1] && cA[2][1] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[0][1]);
                skip = true;
                break;
            }
            if (cA[0][2] == cA[1][2] && cA[1][2] == cA[2][2] && cA[2][2] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[0][2]);
                skip = true;
                break;
            }
            if (cA[0][0] == cA[1][1] && cA[1][1] == cA[2][2] && cA[2][2] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[0][0]);
                skip = true;
                break;
            }
            if (cA[0][2] == cA[1][1] && cA[1][1] == cA[2][0] && cA[2][0] != -1) {
                t_select_ans[{orders[0].first, orders[0].second}].insert(cA[0][2]);
                skip = true;
                break;
            }
        }
        if (skip) continue;
        if (t_score < a_score) {
            t_select_ans[{orders[0].first, orders[0].second}].insert(1);
        } else {
            t_select_ans[{orders[0].first, orders[0].second}].insert(0);
        }
    } while (next_permutation(all(orders)));

    for (auto [k, v] : t_select_ans) {
        auto [x, y] = k;
        if (x == 1 && y == 1) {
            cout << t_select_ans[k] << endl;
        }
        if (v.size() == 1) {
            if (*v.begin() == 1) {
                cout << "Aoki" << endl;
                return 0;
            } else {
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }

    cout << "Aoki" << endl;
}
