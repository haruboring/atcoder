#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

tuple<set<pair<int, int>>, map<int, int>, map<int, int>> solve(int N, int M, vector<int> A, vector<int> B) {
    // int N, M;
    // cin >> N >> M;
    // vector<int> A(M), B(M);
    // rep(i, M) cin >> A[i] >> B[i];

    // rep(i, M) A[i]--, B[i]--;

    set<pair<int, int>> s;
    rep(i, M) s.insert({A[i], B[i]});
    map<int, vector<int>> ys;
    rep(i, M) {
        ys[A[i]].push_back(B[i]);
    }

    map<int, int> cnt_x, cnt_y, mry;
    rep(i, M) {
        cnt_x[A[i]]++;
        cnt_y[B[i]]++;
    }

    set<pair<int, int>> ry;
    rep(i, N) {
        ry.insert({99 * cnt_y[i], i});
        mry[i] = 99 * cnt_y[i];
    }

    rep(x, N) {
        set<pair<int, int>> erase_ry, used;
        for (auto [c, y] : ry) {
            if (cnt_x[x] == M) break;
            if (s.count({x, y})) continue;

            s.insert({x, y});
            cnt_x[x]++;
            cnt_y[y]++;
            erase_ry.insert({c, y});
        }

        for (auto uy : ys[x]) {
            ry.erase({mry[uy], uy});
            ry.insert({mry[uy] + 1, uy});
            mry[uy]++;
        }
        for (auto [ec, ey] : erase_ry) {
            ry.erase({ec, ey});
            ry.insert({ec + 100, ey});
            mry[ey] += 100;
        }
    }

    // cout << s.size() << endl;
    // for (auto [x, y] : s) {
    //     cout << x + 1 << " " << y + 1 << endl;
    // }
    return {s, cnt_x, cnt_y};
}

tuple<set<pair<int, int>>, map<int, int>, map<int, int>> rsolve(int N, int M, vector<int> A, vector<int> B) {
    // int N, M;
    // cin >> N >> M;
    // vector<int> A(M), B(M);
    // rep(i, M) cin >> A[i] >> B[i];

    // rep(i, M) A[i]--, B[i]--;

    set<pair<int, int>> s;
    rep(i, M) s.insert({A[i], B[i]});
    map<int, vector<int>> ys;
    rep(i, M) {
        ys[A[i]].push_back(B[i]);
    }

    map<int, int> cnt_x, cnt_y, mry;
    rep(i, M) {
        cnt_x[A[i]]++;
        cnt_y[B[i]]++;
    }

    set<pair<int, int>> ry;
    rep(i, N) {
        ry.insert({99 * cnt_y[i], i});
        mry[i] = 99 * cnt_y[i];
    }

    for (int x = N - 1; x >= 0; x--) {
        set<pair<int, int>> erase_ry, used;
        for (auto [c, y] : ry) {
            if (cnt_x[x] == M) break;
            if (s.count({x, y})) continue;

            s.insert({x, y});
            cnt_x[x]++;
            cnt_y[y]++;
            erase_ry.insert({c, y});
        }

        for (auto uy : ys[x]) {
            ry.erase({mry[uy], uy});
            ry.insert({mry[uy] + 1, uy});
            mry[uy]++;
        }
        for (auto [ec, ey] : erase_ry) {
            ry.erase({ec, ey});
            ry.insert({ec + 100, ey});
            mry[ey] += 100;
        }
    }

    // cout << s.size() << endl;
    // for (auto [x, y] : s) {
    //     cout << x + 1 << " " << y + 1 << endl;
    // }
    return {s, cnt_x, cnt_y};
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) A[i]--, B[i]--;

    auto [s, cnt_x, cnt_y] = solve(N, M, A, B);
    rep(i, N) {
        if (cnt_x[i] != M || cnt_y[i] != M) {
            debug("bububu");
            auto [s, cnt_x, cnt_y] = rsolve(N, M, A, B);
            cout << s.size() << endl;
            for (auto [x, y] : s) {
                cout << x + 1 << " " << y + 1 << endl;
            }
            return 0;
        }
    }

    cout << s.size() << endl;
    for (auto [x, y] : s) {
        cout << x + 1 << " " << y + 1 << endl;
    }

    // rep(i, N) {
    //     rep(j, N) {
    //         if (s.count({i, j})) {
    //             cout << "o";
    //         } else {
    //             cout << "x";
    //         }
    //     }
    //     cout << endl;
    // }
}