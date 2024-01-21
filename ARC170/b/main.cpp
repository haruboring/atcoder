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
    N++;
    vector<int> A(N);
    rep(i, N - 1) cin >> A[i];
    A[N - 1] = 0;

    // 1から10までの数字をもつ３項の等差数列
    vector<vector<int>> all = {
        {1, 1, 1},
        {1, 2, 3},
        {1, 3, 5},
        {1, 4, 7},
        {1, 5, 9},
        {2, 2, 2},
        {2, 3, 4},
        {2, 4, 6},
        {2, 5, 8},
        {2, 6, 10},
        {3, 2, 1},
        {3, 3, 3},
        {3, 4, 5},
        {3, 5, 7},
        {3, 6, 9},
        {4, 3, 2},
        {4, 4, 4},
        {4, 5, 6},
        {4, 6, 8},
        {4, 7, 10},
        {5, 3, 1},
        {5, 4, 3},
        {5, 5, 5},
        {5, 6, 7},
        {5, 7, 9},
        {6, 4, 2},
        {6, 5, 4},
        {6, 6, 6},
        {6, 7, 8},
        {6, 8, 10},
        {7, 4, 1},
        {7, 5, 3},
        {7, 6, 5},
        {7, 7, 7},
        {7, 8, 9},
        {8, 5, 2},
        {8, 6, 4},
        {8, 7, 6},
        {8, 8, 8},
        {8, 9, 10},
        {9, 5, 1},
        {9, 6, 3},
        {9, 7, 5},
        {9, 8, 7},
        {9, 9, 9},
        {10, 6, 2},
        {10, 7, 4},
        {10, 8, 6},
        {10, 9, 8},
        {10, 10, 10}};

    int l = 0, r = 0;
    vector<int> tmp(0);
    vector<int> free(0);

    int free_size = 0;
    bool a = false;
    vector<int> dup(0);
    while (r < N) {
        if (a) break;

        tmp.push_back(A[r]);
        free_size++;
        r++;

        bool tm = false;

        rep(i, 50) {
            int tmp_i = 0;
            repp(j, l, tmp.size()) {
                if (tmp[j] == all[i][tmp_i]) tmp_i++;
            }
            if (tmp_i == 3) {
                free.push_back(free_size - 1);
                free_size--;

                l++;

                tm = true;

                break;
            }
        }

        if (r == N && !tm) {
            free.push_back(free_size - 1);
        }

        if (tm) {
            while (l < r) {
                bool tm1 = false;
                rep(i, 50) {
                    int tmp_i = 0;
                    repp(j, l, tmp.size()) {
                        if (tmp[j] == all[i][tmp_i]) tmp_i++;
                    }
                    if (tmp_i == 3) {
                        free_size--;

                        l++;

                        tm1 = true;

                        break;
                    }
                }

                if (!tm1) {
                    dup.push_back(free_size - 1);
                    break;
                }
            }
        }
    }

    N--;
    int ans = N * (N - 1) / 2 - (N - 1);
    debug(ans);
    rep(i, free.size()) {
        debug(free[i]);
        debug(free[i] * (free[i] - 1) / 2 - (free[i] - 1));
        ans -= free[i] * (free[i] - 1) / 2 - (free[i] - 1);
    }
    rep(i, dup.size()) {
        debug(dup[i]);
        debug(dup[i] * (dup[i] - 1) / 2 - (dup[i] - 1));
        ans += dup[i] * (dup[i] - 1) / 2 - (dup[i] - 1);
    }

    cout << ans << endl;
}
